#include "widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);


    this->te = new Teacher(this);
    this->tsu = new Student(this);

    //重载函数的绑定处理 使用函数指针去指定函数的地址
    void(Teacher :: *t)(QString) = &Teacher :: hungry;
    void(Student :: *s)(QString) = &Student :: treatFood;

    void(Teacher :: *vt)(void) = &Teacher :: hungry;
    void(Student :: *vs)(void) = &Student :: treatFood;


    //绑定事件
    this->connect(te, t, tsu, s);
    this->connect(te, vt, tsu, vs);
    //手动调用执行
   // this->classOver();

    QPushButton *btn = new QPushButton("Class Over", this);


    //通过内置的事件去执行，内部实现了手动调用这步  调用函数  函数里是触发
    this->connect(btn, &QPushButton :: clicked, this, &Widget :: classOver);

    //  信号 直接 触发  信号
    this->connect(btn, &QPushButton :: clicked, te, vt);
    //中断信号连接
    disconnect(btn, &QPushButton :: clicked, te, vt);

    [=]()
    {
        btn->setText("ClassOver");
    }();

    int index = 100;
    //mutable  按值传递
    this->connect(btn, &QPushButton :: clicked, this, [index]() mutable {
        index++;
        qDebug() << index;
    });

    int res = []() -> int {return 10;}();

    auto res1 = [=] (){return 10;}();

    qDebug() << res1;


     QPushButton *closeBtn = new QPushButton("Close", this);
     closeBtn->move(200, 0);
     this->connect(closeBtn, &QPushButton :: clicked, this, [=](){
         this->close();
     });
}

Widget::~Widget()
{
}

void Widget::classOver()
{
    emit te->hungry();
    emit te->hungry("Cake");
}

