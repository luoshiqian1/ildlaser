#ifndef TOOLS_H
#define TOOLS_H

#include <QWidget>
#include "common.h"

class tools : public QWidget
{
    Q_OBJECT
public:
    explicit tools(QWidget *parent = 0);

signals:
private slots:


private:
    QGraphicsScene *m_qgraptools;
    QGraphicsView *m_qgrapview;


public slots:

public:
     void show();
};

#endif // TOOLS_H
