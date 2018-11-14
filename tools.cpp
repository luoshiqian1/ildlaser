#include "tools.h"

tools::tools(QWidget *parent) : QWidget(parent)
{
    m_qgraptools = new QGraphicsScene();
    m_qgraptools->addText("ildlaser");
  //  m_qgraptools->setForegroundBrush(QColor(255,122,255,100));

    m_qgraptools->setSceneRect(0,0,600,800);
    m_qgrapview = new QGraphicsView(m_qgraptools);
    m_qgrapview->setFixedSize(600, 800);

}

void tools::show()
{
    m_qgrapview->show();

}
