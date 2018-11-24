#ifndef GAM_H
#define GAM_H
#include "common.h"
#include "common.h"
#include "serialthread.h"

#define CHECKDATA 0xAAAAAAAA

class Gam : public QObject
{
    Q_OBJECT

public:
    Gam();
    ~Gam();
    bool init();
    static GamStu* getCheck();
    bool sendCheck(QString comName);
    bool sendStart(QString comName);
    bool sendEnable(QString comName);

public:
    static unsigned char LRC(unsigned char *auchMsg, unsigned short usDataLen);
    static GamStu* gamInit(GamStu* gam_param);
    static GamStu* getGam(quint32 naddr,quint32 ndata);

signals:
    void gamresponse(const QString &s);
};

#endif // GAM_H
