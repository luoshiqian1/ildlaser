#include "plt.h"


QVector<QString> gpltAction = {
    "IN",
    "SP0"
    "SP1",
    "PA",
    "PU",
    "PD",
    "AA",
    "LB"
};


Plt::Plt(QObject *parent) : QObject(parent)
{

}

QVector<XY>* Plt::analyze(QString strPath)
{
    QFile mfile(strPath);

    if (!mfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QLOG_ERROR() << "cann't open the file," << strPath << "err:" << mfile.errorString();
         return NULL;
    }

    QVector<XY> myXY;
    while(!mfile.atEnd())
    {
        QByteArray line = mfile.readLine();
        QString str(line);

        QLOG_INFO() << "lne:" << str;

        QVector<XY>* tmpXY = analyzeStr(str);
        if (tmpXY)
        {
            myXY = myXY + *tmpXY;
            free(tmpXY);
        }
    }

    QLOG_INFO() << myXY.constData();

    mfile.close();

}

QVector<XY>* Plt::analyzeStr(QString strComment)
{
    QVector<XY>* arrayXY = new QVector<XY>;
    if (strComment == "")
    {
        QLOG_ERROR() << "analyzeStr strComment is null";
        return NULL;
    }

    // 以";"分割
    QStringList strList = strComment.split(";");
    for(int i=0;i<strList.count();i++)
    {
        // 删除动作
        for(int j=0;j<gpltAction.count();j++)
        {
            strList[i].replace("",gpltAction[j]);
        }

        QLOG_INFO() << "以;分割:" << strList[i];

        // 以","分割
        QStringList strListXY = strList[i].split(",");
        quint64 ncount = strListXY.count();
        for (int m=0;m<ncount;m=m+2)
        {
            if ((ncount - m) > 1)
            {

                XY xy;
                xy.x = strListXY[m].toInt();
                xy.y = strListXY[m+1].toInt();
                arrayXY->append(xy);
            }

        }
    }

    return arrayXY;
}

