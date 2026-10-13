
#include "Controller.h"

Controller::Controller() : io(), port(io) {
    serialInit();
}

std::string Controller::serialInit()
{
    std::string state;
    try {
        // Configure the serial port (replace with your port name)
        SerialManager::configureSerialPort(port, "COM3", 9600);
        state = "Arduino Board Connected";
    }
    catch (const std::exception& e) {
        state = "Error Configuring Serial Port";
    }
    return state;
}

std::string Controller::sendMessage(std::string message)
{
    if (port.is_open())
    {
        SerialManager::writeToSerialPort(port, message);
        std::string response = SerialManager::readFromSerialPort(port);
        return "Response Received: " + response;
    }
    else
    {
        return "Port Not Open. Configure Port Before Sending A Message";
    }
}