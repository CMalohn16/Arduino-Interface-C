#include "Serial.h"
#include <exception>

using namespace boost;
using namespace std;

int main() {

    printf("Hello World\n");

    asio::io_context io; // Create an IO service
    // Create a serial port object
    asio::serial_port serial(io);

    try {
        // Configure the serial port (replace with your port name)
        configureSerialPort(serial, "COM3", 9600);
    }
    catch (const std::exception& e) {
        cerr << "Error configuring serial port: "
             << e.what() << endl;
        return 1;
    }

    string message = "LED,0,0,0";

    // Write the message to the serial port
    writeToSerialPort(serial, message);
    cout << "Message sent: " << message << endl;

    serial.close(); // Close the serial port
    return 0;
}