#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.h"
#include "testtool.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    this->setFixedSize(800,600);

    myAc1 = new QAction(this);
    myAc1->setText(QString::fromLocal8Bit("新建"));
    myAc1->setStatusTip("This is ac1.");
    myAc1->setShortcut(QKeySequence("Ctrl+8")); //随意指定快捷方式
  //  ui->mainToolBar->addAction(myAc1);           //工具条
    connect(myAc1, SIGNAL(triggered()), this, SLOT(pop1()));

    myAc2 = new QAction(this);
    myAc2->setText(QString::fromLocal8Bit("打开"));
    myAc2->setStatusTip("This is ac2");
    connect(myAc2, SIGNAL(triggered()), this, SLOT(pop2()));

    myAc3 = new QAction(this);
    myAc3->setText(QString::fromLocal8Bit("另存为"));
    myAc3->setStatusTip("This is ac3");
    connect(myAc3, SIGNAL(triggered()), this, SLOT(pop3()));

    acShowTools = new QAction(this);
    acShowTools->setText(QString::fromLocal8Bit("测试工具"));
    acShowTools->setStatusTip("测试工具");
    connect(acShowTools, SIGNAL(triggered()), this, SLOT(showTools()));

    fileMenu = menuBar()->addMenu(QString::fromLocal8Bit("文件"));
    fileMenu->addAction(myAc1);
    fileMenu->addAction(myAc2);
    fileMenu->addAction(myAc3);

    editMenu = menuBar()->addMenu(QString::fromLocal8Bit("编辑"));

    settingMenu = menuBar()->addMenu(QString::fromLocal8Bit("设置"));

    viewMenu = menuBar()->addMenu(QString::fromLocal8Bit("视图"));

    extendMenu = menuBar()->addMenu(QString::fromLocal8Bit("扩展"));

    toolsMenu = menuBar()->addMenu(QString::fromLocal8Bit("工具"));
    toolsMenu->addAction(acShowTools);

    scene1 = new QGraphicsScene(this);
    scene1->addText("ildlaser");
    scene1->setForegroundBrush(QColor(255,122,255,100));
    scene1->setBackgroundBrush(Qt::green);
    scene1->setSceneRect(0,0,600,800);
    view = new QGraphicsView(scene1);
    view->setFixedSize(600, 800);

}

void MainWindow::addScene()
{

}

void MainWindow::showTools()
{
    testtool* tool = new testtool();
    tool->show();
    tool->move ((QApplication::desktop()->width() - tool->width())/2,(QApplication::desktop()->height() - tool->height())/2);

}
void MainWindow::pop1()
{
 //   QMessageBox m(this);
 //   m.setWindowTitle("MyAction1");
 //   m.setText("This is a messagebox for my action1.");
 //   m.exec();
    view->show();



}

void MainWindow::pop2()
{
    QMessageBox m(this);
    m.setWindowTitle("MyAction2");
    m.setText("This is a messagebox for my action2.");
    m.exec();
}

void MainWindow::pop3()
{
    QMessageBox m(this);
    m.setWindowTitle("MyAction3");
    m.setText("This is a messagebox for my action3.");
    m.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
