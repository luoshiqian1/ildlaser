#include "serialthread.h"
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

SerialThread::SerialThread()
{
    quit = false;
    waitTimeout = 5*1000;
}

SerialThread::~SerialThread()
{
    quit = true;
    mutex.lock();
    cond.wakeOne();
    mutex.unlock();
    wait();
}

void SerialThread::startMark(const QString &portName, QByteArray &Input)
{
    QMutexLocker locker(&mutex);
    this->strComName = portName;
    this->pInput = Input;

    if (!isRunning())
        start();
    else
        cond.wakeOne();

}


void SerialThread::run()
{
    bool currentPortNameChanged = false;
    QString currentPortName = "null";
    QSerialPort serial;

    while (!quit) {
        mutex.lock();

       // if (currentPortName == "")
       //     return;
        if (currentPortName != strComName) {
            currentPortName = strComName;
            currentPortNameChanged = true;
        }

        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);
            serial.setBaudRate(BaudRate);

            if (!serial.open(QIODevice::ReadWrite)){
                 emit timeout(QString::fromLocal8Bit("´ò¿ª´®¿ÚÊ§°Ü"));
                 return;
            }
        }

        serial.write(pInput);

        if (serial.waitForBytesWritten(waitTimeout)) {
            // read response
            if (serial.waitForReadyRead(waitTimeout)) {
                QByteArray responseData = serial.readAll();
                while (serial.waitForReadyRead(10))
                    responseData += serial.readAll();

                QString response(responseData);

                emit this->response(response);

            } else {
                emit timeout(QString::fromLocal8Bit("Wait read response timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
        } else {
            emit timeout(QString::fromLocal8Bit("Wait write request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }


        cond.wait(&mutex);
        mutex.unlock();
    }

}
