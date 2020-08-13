#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treatFood()
{
    qDebug() << "void Eat";
}

void Student::treatFood(QString food)
{
                            //先转成 QByteArray
    qDebug() << "Eat " << food.toUtf8().data();
}
