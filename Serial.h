#pragma once

#include <boost/asio.hpp>
#include <string.h>
#include <iostream>

void configureSerialPort(boost::asio::serial_port& serial,
                         const std::string& portname,
                         unsigned int baud_rate);

void writeToSerialPort(boost::asio::serial_port& serial,
                       const std::string& message);