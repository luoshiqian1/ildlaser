#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "common.h"

class scene : public QWidget
{
    Q_OBJECT
public:
    explicit scene(QWidget *parent = 0);

signals:
public slots:
    void addScene();

};

#endif // SCENE_H
