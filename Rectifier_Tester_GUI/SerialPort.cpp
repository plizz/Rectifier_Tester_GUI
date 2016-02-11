#include "SerialPort.h"

SerialPort::SerialPort(const std::string comPortName)
	: comPortName_(comPortName),
	io_service_(),
	cb_(nullptr)
{
}

SerialPort::~SerialPort()
{
	if (port_) {
		port_->cancel();
		port_->close();
		port_.reset();
	}
	stopIoService();
}

void SerialPort::begin(uint32_t baudRate) {
	port_ = boost::shared_ptr<boost::asio::serial_port>(new boost::asio::serial_port(io_service_));
	boost::system::error_code ec;
	try {
		port_->open(comPortName_);
	}
	catch (boost::system::system_error error) {
		throw;
	}
	port_->set_option(boost::asio::serial_port_base::baud_rate(baudRate));
	port_->set_option(boost::asio::serial_port_base::character_size(8));
	port_->set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
	port_->set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));

	waitReceive();
	startIoService();
}

void SerialPort::startIoService()
{
	if (thread_) return; // running

	thread_.reset(new boost::thread(
		boost::bind(&boost::asio::io_service::run, &io_service_)
		));
}

void SerialPort::stopIoService()
{
	if (!thread_) return; // stopped

	io_service_.stop();
	thread_->join();
	io_service_.reset();
	thread_.reset();
}

void SerialPort::waitReceive() {
	port_->async_read_some(boost::asio::buffer(readBuffer_, SERIAL_PORT_READ_BUF_SIZE), [this](const boost::system::error_code& error, std::size_t bytesTransferred)
	{
		if (!error) {
			waitReceive();
		}
		if (cb_ != nullptr) {
			cb_->onReceive(readBuffer_, bytesTransferred);
		}
	});

}

void SerialPort::connectCallback(CallbackInterface* cb) {
	cb_ = cb;
}

void SerialPort::write(const char* sendMessage, uint8_t sendMessageLength) {
	boost::asio::write(*port_, boost::asio::buffer(sendMessage, sendMessageLength));
}