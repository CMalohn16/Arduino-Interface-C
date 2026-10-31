#include "widget.h"
#include "build/MyProject_autogen/include/ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), 
    ui(new Ui::Widget),
    controller()
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &Widget::handleMsgBtn);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &Widget::checkStatus);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::name() const
{
    return ui->lineEdit->text();
}

void Widget::handleMsgBtn()
{
    // std::string message = this->name().toStdString();
    // SerialManager::writeToSerialPort(port, message);
    // //std::cout << "Message sent: " << message << std::endl;
    // ui->debug_label->setText(this->name());
    
    // std::string response = SerialManager::readFromSerialPort(port);
    // if (!response.empty()) {
    //     ui->debug_label->setText(QString::fromStdString("Response Received: " + response));
    // }
    ui->debug_label->setText(QString::fromStdString(controller.sendMessage((this->name()).toStdString())));
}

void Widget::checkStatus()
{
    ui->label_2->setText(QString::fromStdString(controller.serialInit()));
}