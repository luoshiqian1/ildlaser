#include "gam.h"

quint32 gnBaseAddr;                 // 内存基地址

Gam::Gam()
{

}

Gam::~Gam()
{

}

bool Gam::init()
{
    return true;
}

// 振镜开始转动
bool Gam::sendStart(QString comName)
{
    QSerialPort serial;
    serial.setPortName(comName);
    serial.setBaudRate(BAUD_RATE);

    if (!serial.open(QIODevice::ReadWrite)){
        QString sout = QString("sendEnable open com:%1 fail,err:%2").arg(comName,serial.errorString());
        emit gamresponse(sout);
        QLOG_ERROR() << sout;
        return false;
    }

    GamStu* strIn = new GamStu();
    if (strIn = NULL)
    {
        QLOG_ERROR() << "sendEnable malloc GamStu fail,please check system have enough available memory";
        return false;
    }

    gamInit(strIn);
    strIn->addr = gnBaseAddr + REG_SEND_START_ADDR;
    strIn->ndata = 1;
    QByteArray requestData((char*)strIn,sizeof(GamStu));

    serial.write(requestData);
    if (serial.waitForBytesWritten(WAIT_TIMEOUT)) {
        emit gamresponse(QString::fromLocal8Bit("Write complete"));

    } else {
        emit gamresponse(QString::fromLocal8Bit("Wait write request timeout"));
    }

    free(strIn);

    return true;
}


// 使能振镜
bool Gam::sendEnable(QString comName)
{
    QSerialPort serial;
    serial.setPortName(comName);
    serial.setBaudRate(BAUD_RATE);

    if (!serial.open(QIODevice::ReadWrite)){
        QString sout = QString("sendEnable open com:%1 fail,err:%2").arg(comName,serial.errorString());
        emit gamresponse(sout);
        QLOG_ERROR() << sout;
        return false;
    }

    GamStu* strIn = new GamStu();
    if (strIn = NULL)
    {
        QLOG_ERROR() << "sendEnable malloc GamStu fail,please check system have enough available memory";
        return false;
    }

    gamInit(strIn);
    strIn->addr = gnBaseAddr + REG_SEND_ENABLE_ADDR;
    strIn->ndata = 1;
    QByteArray requestData((char*)strIn,sizeof(GamStu));

    serial.write(requestData);
    if (serial.waitForBytesWritten(WAIT_TIMEOUT)) {
        emit gamresponse(QString::fromLocal8Bit("Write complete"));

    } else {
        emit gamresponse(QString::fromLocal8Bit("Wait write request timeout"));
    }

    free(strIn);

    return true;
}

// 测试信号板卡是否正常
bool Gam::sendCheck(QString comName)
{
    QSerialPort serial;
    serial.setPortName(comName);
    serial.setBaudRate(BAUD_RATE);

    if (!serial.open(QIODevice::ReadWrite)){
        QString sout = QString("open com:%1 fail,err:%2").arg(comName,serial.errorString());
        emit gamresponse(sout);
        QLOG_ERROR() << sout;
        return false;
    }

    GamStu* strIn = getCheck();
    if (strIn = NULL)
    {
        QLOG_ERROR() << "malloc GamStu fail,please check system have enough available memory";
        return false;
    }

    QByteArray requestData((char*)strIn,sizeof(GamStu));

    serial.write(requestData);
    if (serial.waitForBytesWritten(WAIT_TIMEOUT)) {
        emit gamresponse(QString::fromLocal8Bit("Write complete"));
        // read response
        /*
        if (serial.waitForReadyRead(WAIT_TIMEOUT)) {
            QByteArray responseData = serial.readAll();
            while (serial.waitForReadyRead(10))
                responseData += serial.readAll();

            QString response(responseData);

            emit this->response(response);

        } else {
            emit timeout(QString::fromLocal8Bit("Wait read response timeout %1")
                         .arg(QTime::currentTime().toString()));
        }
        */

    } else {
        emit gamresponse(QString::fromLocal8Bit("Wait write request timeout"));
    }

    free(strIn);

    return true;
}

// 测试信号板卡是否正常
 GamStu* Gam::getCheck()
{
    GamStu* gamchk = NULL;
    gamchk = new GamStu();
    if (gamchk == NULL)
        return NULL;

    gamInit(gamchk);
    gamchk->addr = gnBaseAddr + REG_TEST_ADDR;
    gamchk->ndata = CHECKDATA;
    gamchk->lrc = LRC((unsigned char*)gamchk,LRC_LEN);

    return gamchk;
}

 // 获取gamstu结构
 GamStu* Gam::getGam(quint32 naddr,quint32 ndata)
 {
     GamStu* gamchk = NULL;
     gamchk = new GamStu();
     if (gamchk == NULL)
         return NULL;

     gamInit(gamchk);
     gamchk->addr = gnBaseAddr + naddr;
     gamchk->ndata = ndata;
     gamchk->lrc = LRC((unsigned char*)gamchk,LRC_LEN);

     return gamchk;
 }

// 初始化通讯协议
GamStu* Gam::gamInit(GamStu* gam_param)
{
    if (gam_param == NULL)
        return NULL;

    gam_param->header[0] = HEADER0;
    gam_param->header[1] = HEADER1;
    gam_param->header[2] = HEADER2;

    gam_param->end[0] = END0;
    gam_param->end[1] = END1;

    return gam_param;
}

/* auchMsg: message to calculate */
/* usDataLen: LRC upon quantity of bytes in message */
unsigned char Gam::LRC(unsigned char *auchMsg, unsigned short usDataLen)
{
    unsigned char uchLRC = 0 ;      /* LRC char initialized */
    while (usDataLen--)             /* pass through message */
        uchLRC += *auchMsg++ ;      /* buffer add buffer byte without carry */
    return uchLRC ; /* return two's complemen */
}

