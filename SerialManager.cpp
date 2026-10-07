#include <stdio.h>
#include "SerialManager.h"

using namespace boost;


void SerialManager::configureSerialPort(asio::serial_port& serial,
                                        const std::string& portname,
                                        unsigned int baud_rate)
{
    serial.open(portname);
    serial.set_option(
        asio::serial_port_base::baud_rate(baud_rate));
}

void SerialManager::writeToSerialPort(asio::serial_port& serial,
                                    const std::string& message)
{
    system::error_code ec;
    asio::write(serial, asio::buffer(message), ec);
    if (ec) {
        std::cerr << "Error writing to serial port: "
            << ec.message() << std::endl;
    }
}

std::string SerialManager::readFromSerialPort(asio::serial_port& serial)
{
    char c;
    std::string result;
    for(;;)
    {
        asio::read(serial,asio::buffer(&c,1));
        switch(c)
        {
            case '\r':
                break;
            case '\n':
                return result;
            default:
                result+=c;
        }
    }
}