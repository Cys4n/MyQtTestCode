#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew, &QAction :: triggered, [=](){

        //模态
        //        QDialog dlg(this);
        //        dlg.resize(300, 200);
        //        dlg.exec();

        //非模态
        QDialog *dlg2 = new QDialog(this);
        dlg2->resize(300, 200);

        //手动释放对象内存
        dlg2->setAttribute(Qt :: WA_DeleteOnClose);
        dlg2->show();



    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

