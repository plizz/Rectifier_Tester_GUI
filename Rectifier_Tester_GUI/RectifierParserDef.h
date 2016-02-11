#ifndef H_RECTIFIER_PARSER_DEFS
#define H_RECTIFIER_PARSER_DEFS

#define RECTIFIER_START_BYTE 0x7E
#define RECTIFIER_END_BYTE 0x0D

#define RECTIFIER_BROADCAST_ADDRESS 99

// SOI		Start flag		1 byte
// ADDR		Device address	1 byte
// LENGTH					1 byte
#define RECTIFIER_MIN_LENGTH 3U

// CHKSUM	Checksum		1 byte
// EOI		End of frame	1 byte
#define RECTIFIER_CS_TAIL_LENGTH 2U

#define MAX_CHKSUM_NUMBER 256


enum RectifierOrder {
	ISSUED_BOARD_REGISTRATION = 0x01,		// Board Registration Response	
	UPLOAD_BOARD_REGISTRATION = 0x81,		// Board Registration Response
	ISSUED_VERSION_NUMBER = 0x02,			// Get the version number	
	UPLOAD_VERSION_NUMBER = 0x82,			// Get the version number
	ISSUED_GET_OUTPUT_PARAMETERS = 0x03,	// Get the rectifier output voltage, current, alarm volume	
	UPLOAD_GET_OUTPUT_PARAMETERS = 0x83,	// Get the rectifier output voltage, current, alarm volume
	ISSUED_CONTROL_ON_OFF = 0x04,			// Control ON / OFF	
	UPLOAD_CONTROL_ON_OFF = 0x84,			// Control ON / OFF
	ISSUED_GET_RECTIFIER_SERIES = 0x05,		// Get rectifier module series	
	UPLOAD_GET_RECTIFIER_SERIES = 0x85,		// Get rectifier module series
	ISSUED_SET_OUTPUT_PARAMETERS = 0x06,	// Set the rectifier output voltage, current	
	UPLOAD_SET_OUTPUT_PARAMETERS = 0x86,	// Set the rectifier output voltage, current
	ISSUED_GET_VOLTAGE_AND_CURRENT = 0x07,	// Get rectifier voltage and current set parameters	
	UPLOAD_GET_VOLTAGE_AND_CURRENT = 0x87,	// Get rectifier voltage and current set parameters
	ISSUED_GET_SERIAL_NUMBER = 0X10,		// Get module serial number	
	UPLOAD_GET_SERIAL_NUMBER = 0X90,		// Get module serial number	
	ISSUED_GET_INFORMATION = 0X11,			// Get module manufacturers information	
	UPLOAD_GET_INFORMATION = 0X91			// Get module manufacturers information
};

#endif // H_RECTIFIER_PARSER_DEFS