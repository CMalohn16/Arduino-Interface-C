#include "SerialManager.h"
#include <exception>

using namespace boost;
using namespace std;

int main() {

    asio::io_context io; // Create an IO service
    // Create a serial port object
    asio::serial_port port(io);

    try {
        // Configure the serial port (replace with your port name)
        SerialManager::configureSerialPort(port, "COM3", 9600);
    }
    catch (const std::exception& e) {
        std::cerr << "Error configuring serial port: "
             << e.what() << std::endl;
        return 1;
    }

    /*****************************************
     * Message Format
     *  LED,r,g,b turns the RGB LED to the specified color
     *  PORT,#,1/0 turns port number # on or off;
     */
    
    std::string message;

    while (true) {
        cout << "Enter message to send to arduino board or q to quit:" << endl;

        cin >> message;

        if (message == "quit" || message == "q") {
            port.close(); // Close the serial port
            return 0;
        }

        // Write the message to the serial port
        SerialManager::writeToSerialPort(port, message);
        cout << "Message sent: " << message << endl;

        std::string response = SerialManager::readFromSerialPort(port);
        if (!response.empty()) {
            cout << "Response received: " << response << endl;
        }
    }
}