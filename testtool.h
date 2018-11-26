#ifndef TESTTOOL_H
#define TESTTOOL_H

#include <QDialog>
#include "common.h"
#include "serialthread.h"
#include <QtSerialPort/QSerialPortInfo>
#include "gam.h"

namespace Ui {
class testtool;
}

class testtool : public QDialog
{
    Q_OBJECT

public:
    explicit testtool(QWidget *parent = 0);
    ~testtool();
     void ildlaserInit();

private slots:
    void on_btn_scan_clicked();
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);



    void on_btInit_clicked();

    void on_btreadfile_clicked();

private:
    Ui::testtool *ui;
    SerialThread thread;
    Gam tgam;
    uint32_t nbaseAddr;         //»ùµØÖ·


private:

};

#endif // TESTTOOL_H
