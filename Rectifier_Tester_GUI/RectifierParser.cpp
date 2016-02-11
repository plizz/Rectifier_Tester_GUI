#include "RectifierParser.h"

uint8_t getCheckSum(const char* data, uint8_t length) {
	uint16_t sum = 0;
	for (uint8_t it = 0; it < length; it++) {
		sum += (uint8_t)*(data + it);
		// TODO Check this!
		if (sum > MAX_CHKSUM_NUMBER) sum -= MAX_CHKSUM_NUMBER;
	}
	return (uint8_t)(sum % 100);
}

bool checkChksumAndEndFrame(const char*& data, uint16_t& bytesRead, uint8_t frameLength) {
	if (bytesRead < RECTIFIER_CS_TAIL_LENGTH) {
		return false;
	}

	uint8_t length = frameLength + RECTIFIER_MIN_LENGTH - 1;
	uint8_t calcChksum = getCheckSum(data - length, length);
	uint8_t oneByte;
	if (0 != readFromBufLe((uint8_t*)&oneByte, (uint16_t)sizeof(oneByte), data, bytesRead, true)) {
		return false;
	}
	if (calcChksum != oneByte)  {
		return false;
	}
	if (!checkByte(RECTIFIER_END_BYTE, data, bytesRead)) {
		return false;
	}
	return true;
}

void getTwoByteBcdFromDouble(char* data, uint8_t& pos, double value, int multiply) {
	value *= multiply;
	int seconsPart = (int)value % 100;
	int firstPart = ((int)value - seconsPart) / 100;
	*(data + pos) = decToBcd(firstPart);
	pos++;
	*(data + pos) = decToBcd(seconsPart);
	pos++;
}

// The callback function that RectifierParser will call.
void RectifierParser::onReceive(const char* data, uint16_t bytesRead)
{
	if (!checkByte(RECTIFIER_START_BYTE, data, bytesRead))  {
		return;
	}
	BUFFER_READ_BCD(frame_.address, data, bytesRead);
	if (address_ != frame_.address && frame_.address != RECTIFIER_BROADCAST_ADDRESS) {
		return;
	}

	BUFFER_READ_BCD(frame_.length, data, bytesRead);
	if (frame_.length > (bytesRead - RECTIFIER_CS_TAIL_LENGTH))    {
		return;
	}

	BUFFER_READ(frame_.cid, data, bytesRead);

	infoDataSize_ = frame_.length - 1;	// cid size in frame length
	if (infoDataSize_ > 0) {
		memcpy(infoData_, data, infoDataSize_);
		data += infoDataSize_;
		bytesRead -= infoDataSize_;
	}

	if (checkChksumAndEndFrame(data, bytesRead, frame_.length)) {
		sendAnswer();
	}
	if (bytesRead > 0) {
		onReceive(data, bytesRead);
	}
}

void RectifierParser::sendGetOutputParametersAnswer() {
	char infoPart[11];
	uint8_t pos = 0;
	infoPart[pos++] = (char)RECTIFIER_ANSWER_RESPONCE_RESULT;
	getTwoByteBcdFromDouble(infoPart, pos, rectifierParameters_.voltage, 10);
	getTwoByteBcdFromDouble(infoPart, pos, rectifierParameters_.current, 10);
	double fanValue = 50.0;
	getTwoByteBcdFromDouble(infoPart, pos, fanValue, 10);
	// 0
	getTwoByteBcdFromDouble(infoPart, pos, 0, 10);
	//Module alarm volume(1 byte)
	uint8_t alarmVolume = 0;
	alarmVolume |= rectifierParameters_.isLimitFlag ? 0x01 : 0;
	alarmVolume |= rectifierParameters_.isModuleFault ? 0x02 : 0;
	alarmVolume |= rectifierParameters_.isModuleSwitch ? 0x04 : 0;
	alarmVolume |= rectifierParameters_.isFanFailure ? 0x10 : 0;
	alarmVolume |= rectifierParameters_.isAcFault ? 0x20 : 0;
	alarmVolume |= rectifierParameters_.isAlarm ? 0x40 : 0;
	infoPart[pos++] = alarmVolume;
	//Module protection type(1 byte)
	infoPart[pos++] = rectifierParameters_.protectionCode;

	buildSimpleIssuedMessage(RectifierOrder::UPLOAD_GET_OUTPUT_PARAMETERS, address_, infoPart, sizeof(infoPart));
}

void RectifierParser::sendSetOutputParametersAnswer() {
	char infoPart[5];
	uint8_t pos = 0;
	infoPart[pos++] = (char)RECTIFIER_ANSWER_RESPONCE_RESULT;
	getTwoByteBcdFromDouble(infoPart, pos, rectifierParameters_.voltage, 10);
	getTwoByteBcdFromDouble(infoPart, pos, rectifierParameters_.current, 10);

	buildSimpleIssuedMessage(RectifierOrder::UPLOAD_SET_OUTPUT_PARAMETERS, address_, infoPart, sizeof(infoPart));
}

void RectifierParser::sendGetVoltageAndCurrentAnswer() {
	char infoPart[5];
	uint8_t pos = 0;
	infoPart[pos++] = (char)RECTIFIER_ANSWER_RESPONCE_RESULT;
	getTwoByteBcdFromDouble(infoPart, pos, rectifierSetParameters_.voltage, 10);
	getTwoByteBcdFromDouble(infoPart, pos, rectifierSetParameters_.current, 10);

	std::ostringstream strs;
	strs << "GET: VOLTAGE=" << rectifierSetParameters_.voltage << " CURRENT=" << rectifierSetParameters_.current;
	std::string str = strs.str();
	outVector_->push_back(str);

	buildSimpleIssuedMessage(RectifierOrder::UPLOAD_GET_VOLTAGE_AND_CURRENT, address_, infoPart, sizeof(infoPart));
}

void RectifierParser::buildSimpleIssuedMessage(char cid, uint8_t address, char* info, uint8_t infoLength) {
	sendMessageLength_ = 0;
	sendMessage_[sendMessageLength_++] = (char)RECTIFIER_START_BYTE;
	sendMessage_[sendMessageLength_++] = decToBcd(address);
	sendMessage_[sendMessageLength_++] = decToBcd(infoLength + 1);
	sendMessage_[sendMessageLength_++] = cid;
	memcpy(sendMessage_ + sendMessageLength_, info, infoLength);
	sendMessageLength_ += infoLength;
	uint8_t chksum = getCheckSum(sendMessage_ + 1, sendMessageLength_ - 1);
	sendMessage_[sendMessageLength_++] = decToBcd(chksum);
	sendMessage_[sendMessageLength_++] = (char)RECTIFIER_END_BYTE;

	serial_.write(sendMessage_, sendMessageLength_);
}

void RectifierParser::setOutputParametersHandler() {
	uint16_t twoByte;
	const char* pData = infoData_;
	BUFFER_READ_BCD(twoByte, pData, infoDataSize_);
	rectifierSetParameters_.voltage = twoByte / 10.0;
	BUFFER_READ_BCD(twoByte, pData, infoDataSize_);
	rectifierSetParameters_.current = twoByte / 10.0;

	std::ostringstream strs;
	strs << "SET: VOLTAGE=" << rectifierSetParameters_.voltage << " CURRENT=" << rectifierSetParameters_.current;
	std::string str = strs.str();
	outVector_->push_back(str);
}

void RectifierParser::sendAnswer() {
	switch (frame_.cid) {
	case ISSUED_GET_OUTPUT_PARAMETERS:
		if (frame_.address != RECTIFIER_BROADCAST_ADDRESS)
			sendGetOutputParametersAnswer();
		break;
	case ISSUED_SET_OUTPUT_PARAMETERS:
		setOutputParametersHandler();
		if (frame_.address != RECTIFIER_BROADCAST_ADDRESS)
			sendSetOutputParametersAnswer();
		break;
	case ISSUED_GET_VOLTAGE_AND_CURRENT:
		if (frame_.address != RECTIFIER_BROADCAST_ADDRESS)
			sendGetVoltageAndCurrentAnswer();
		break;
	default:
		break;
	}
}

RectifierParser::RectifierParser(const std::string comPortName, RectifierParameters& rectifierParameters, std::vector<std::string>* outVector)
	: serial_(comPortName),
	rectifierParameters_(rectifierParameters),
	address_(RECTIFIER_ADDRESS),
	outVector_(outVector)
{
	try {
		serial_.begin(RECTIFIER_BAUD_RATE);
	}
	catch (boost::system::system_error error) {
		throw;
	}

	rectifierSetParameters_.voltage = RECTIFIER_DEFAULT_VOLTAGE;
	rectifierSetParameters_.current = RECTIFIER_DEFAULT_CURRENT;

	serial_.connectCallback(this);
}


RectifierParser::~RectifierParser()
{
}
