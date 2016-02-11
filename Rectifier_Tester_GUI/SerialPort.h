#pragma once

#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include <functional>
#include <boost/thread.hpp>

#include <stdint.h>

#define SERIAL_PORT_READ_BUF_SIZE 256

class CallbackInterface
{
public:
	virtual void onReceive(const char*, uint16_t) = 0;
};

class SerialPort
{
public:
	SerialPort(const std::string comPortName);
	void begin(uint32_t baudRate);

	void connectCallback(CallbackInterface* cb);

	void write(const char* sendMessage,	uint8_t sendMessageLength);

	~SerialPort();
private:
	void waitReceive();

	void startIoService();
	void stopIoService();

	const std::string comPortName_;
	boost::shared_ptr<boost::asio::serial_port> port_;
	boost::asio::io_service io_service_;
	std::unique_ptr<boost::thread> thread_;
	char readBuffer_[SERIAL_PORT_READ_BUF_SIZE];

	CallbackInterface* cb_;

};

