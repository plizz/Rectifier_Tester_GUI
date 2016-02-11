#pragma once

#include <string.h>
#include "SerialPort.h"
#include "ReadWriteUtility.h"
#include "RectifierParserDef.h"

// Rectifier settings
#define RECTIFIER_ADDRESS			1
#define RECTIFIER_BAUD_RATE			4800

#define RECTIFIER_DEFAULT_VOLTAGE	270.3
#define RECTIFIER_DEFAULT_CURRENT	5.2

#define RECTIFIER_ANSWER_RESPONCE_RESULT 0	// 0 means normal
#define INFO_DATA_SIZE				64
#define SEND_MESSAGE_LENGTH			80

struct RectifierFrame {
	uint8_t address;
	uint8_t length;
	uint8_t cid;
	void* info;
};

class RectifierSetParameters {
public:
	double voltage;
	double current;
};

class RectifierParameters {
public:
	double voltage;
	double current;
	bool isLimitFlag;
	bool isModuleFault;
	bool isModuleSwitch;
	bool isFanFailure;
	bool isAcFault;
	bool isAlarm;
	uint8_t protectionCode;
};

class RectifierParser : CallbackInterface
{
public:
	RectifierParser(const std::string comPortName, RectifierParameters& rectifierParameters_);
	~RectifierParser();

	void onReceive(const char*, uint16_t);
private:

	void sendAnswer();
	void sendGetOutputParametersAnswer();
	void sendSetOutputParametersAnswer();
	void sendGetVoltageAndCurrentAnswer();

	void setOutputParametersHandler();

	void buildSimpleIssuedMessage(char cid, uint8_t address, char* info, uint8_t infoLength);
	SerialPort serial_;
	RectifierFrame frame_;
	RectifierParameters& rectifierParameters_;

	RectifierSetParameters rectifierSetParameters_;

	uint8_t address_;

	char infoData_[INFO_DATA_SIZE];
	uint16_t infoDataSize_;

	char sendMessage_[SEND_MESSAGE_LENGTH];
	uint8_t sendMessageLength_;
};

