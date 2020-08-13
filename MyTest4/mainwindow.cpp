#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("E:\\test1.jpg"));

    //添加QT资源
    ui->actionnew->setIcon(QIcon(":/new/prefix1/test1.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
