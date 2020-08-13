#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->setText("Click1");


    QPushButton *btn2= new QPushButton("Click2", this);
    //this->resize(800, 600);
    btn2-> move(300, 200);
    this->setWindowTitle("MyApp");
    this->setFixedSize(800, 600);
    this->connect(btn2, &QPushButton :: clicked, this, &Widget :: close);


}

Widget::~Widget()
{
}

