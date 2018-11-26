#ifndef PLT_H
#define PLT_H

#include <QObject>
#include <qfile.h>
#include "common.h"

class Plt : public QObject
{
    Q_OBJECT
public:
    explicit Plt(QObject *parent = 0);
    QVector<XY>* analyze(QString strPath);
    QVector<XY>* analyzeStr(QString strComment);

signals:

private:
    QFile mfile;
public slots:
};

#endif // PLT_H
