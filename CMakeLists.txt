cmake_minimum_required(VERSION 3.8...3.31)
project(Arduino)

find_package(Boost REQUIRED)
add_executable(Arduino src/ArduinoInterface.cpp src/SerialManager.cpp)
target_link_libraries(Arduino Boost::headers)