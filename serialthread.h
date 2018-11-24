#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "common.h"

class SerialThread : public QThread
{
    Q_OBJECT
public:
    SerialThread();
    ~SerialThread();
    void run();
    void startMark(const QString &portName, QByteArray &Input);

private:
    QByteArray pInput;
    quint64 nDataLen;
    QString strInput;
    QString strComName;
    int waitTimeout;
    const int BaudRate = 115200;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;

signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
};

#endif // SERIALTHREAD_H
