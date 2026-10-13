cmake_minimum_required(VERSION 3.21)
project(MyProject LANGUAGES CXX)


find_package(Boost REQUIRED)
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()


qt_add_executable(MyProject
    WIN32 MACOSX_BUNDLE
    SerialManager.cpp
    Controller.cpp
    widget.cpp
    widget.h
    widget.ui
    ArduinoInterface.cpp
)

target_link_libraries(MyProject PRIVATE Boost::headers Qt::Core Qt::Widgets)

install(TARGETS MyProject
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MyProject
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
