#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include "scene.h"

#include "tools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void pop1();
    void pop2();
    void pop3();

    void showTools();

public slots:
    void addScene();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *settingMenu;
    QMenu *viewMenu;
    QMenu *extendMenu;
    QMenu *toolsMenu;

    QAction *myAc1;
    QAction *myAc2;
    QAction *myAc3;

    QAction *acShowTools;


    QGraphicsScene *scene1;
    QGraphicsView *view;
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HIGH=768;

};

#endif // MAINWINDOW_H
