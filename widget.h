#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

    QString name() const;
    void handleMsgBtn();
    void checkStatus();
private:
    Ui::Widget *ui;
    QPushButton *messageBtn;
    Controller controller;
};
#endif // WIDGET_H
