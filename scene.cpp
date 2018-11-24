#include "scene.h"

#include <QGraphicsScene>
#include <QGraphicsView>

scene::scene(QWidget *parent) : QWidget(parent)
{

}

void scene::addScene()
{
    QGraphicsScene scene;
    scene.addText("ildlaser");
    scene.setForegroundBrush(QColor(255,122,255,100));
    scene.setBackgroundBrush(Qt::green);
    scene.setSceneRect(0,0,600,800);
    QGraphicsView view(&scene);
    view.setFixedSize(600, 800);
    view.show();

}
