#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    void treatFood();
    void treatFood(QString food);
signals:

};

#endif // STUDENT_H
