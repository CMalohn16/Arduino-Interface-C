#pragma once

#include <boost/asio.hpp>
#include <string.h>
#include <iostream>

using namespace boost;

class SerialManager {
public:

    static void configureSerialPort(asio::serial_port& serial,
                             const std::string& portname,
                             unsigned int baud_rate);

    static void writeToSerialPort(asio::serial_port& serial,
                           const std::string& message);

    static std::string readFromSerialPort(asio::serial_port& serial);

};
