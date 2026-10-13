#include "SerialManager.h"

class Controller
{
    public:
        Controller();
        std::string serialInit();
        std::string sendMessage(std::string message);
    private:
        boost::asio::io_context io;
        boost::asio::serial_port port;
};