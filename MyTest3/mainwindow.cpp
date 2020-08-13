#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(800, 600);

    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    QAction *qa1 = fileMenu->addAction("1111");
    fileMenu->addSeparator();
    QAction *qa2 = fileMenu->addAction("2222");
    fileMenu->addSeparator();
    QAction *qa3 = fileMenu->addAction("3333");


    editMenu->addAction("1111");
    editMenu->addSeparator();
    editMenu->addAction("2222");
    editMenu->addSeparator();
    editMenu->addAction("3333");

    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt :: LeftToolBarArea, toolBar);
   // toolBar->setAllowedAreas(Qt :: LeftToolBarArea | Qt :: RightToolBarArea);
    toolBar->setFloatable(false);
    toolBar->addAction(qa1);
    toolBar->addSeparator();
    toolBar->addAction(qa2);
    toolBar->addSeparator();
    toolBar->addAction(qa3);

    QPushButton *btn = new QPushButton("click", this);
    toolBar->addWidget(btn);


    QStatusBar *qsb = statusBar();
    setStatusBar(qsb);

    QLabel *ql = new QLabel("Info", this);
    qsb->addWidget(ql);

    QLabel *ql2 = new QLabel("Info", this);
    qsb->addPermanentWidget(ql2);



    QDockWidget *dockw = new QDockWidget("Float", this);
    addDockWidget(Qt :: BottomDockWidgetArea, dockw);



    //Center
    QTextEdit *qte = new QTextEdit(this);
    setCentralWidget(qte);




}

MainWindow::~MainWindow()
{
}

