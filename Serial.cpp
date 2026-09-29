#include <stdio.h>
#include "Serial.h"

using namespace std;
using namespace boost;

void configureSerialPort(asio::serial_port& serial,
                         const string& portname,
                         unsigned int baud_rate)
{
    serial.open(portname);
    serial.set_option(
        asio::serial_port_base::baud_rate(baud_rate));
}

void writeToSerialPort(asio::serial_port& serial,
                       const string& message)
{
    system::error_code ec;
    asio::write(serial, asio::buffer(message), ec);
    if (ec) {
        cerr << "Error writing to serial port: "
             << ec.message() << endl;
    }
}