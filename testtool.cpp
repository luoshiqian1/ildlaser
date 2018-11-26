#include "testtool.h"
#include "ui_testtool.h"
#include "serialthread.h"
#include "gam.h"
#include "log.h"
#include "plt.h"

Log mylog;
QVector<GamStu> array(4);
QVector<GamStu> arrayY(4);
QByteArray gInput;

testtool::testtool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testtool)
{
    ui->setupUi(this);
    ildlaserInit();

}

testtool::~testtool()
{
    delete ui;
}

void testtool::ildlaserInit()
{


    nbaseAddr = 0;
    int i = 0;
    QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    foreach (const QSerialPortInfo &info, infos)
    {
        i++;
        ui->cb_serialport->insertItem(i,info.portName());
    }
    // 连接信号
    connect(&thread, &SerialThread::response, this, &testtool::showResponse);
    connect(&thread, &SerialThread::error, this, &testtool::processError);
    connect(&thread, &SerialThread::timeout, this, &testtool::processTimeout);

    connect(&tgam, &Gam::gamresponse, this, &testtool::showResponse);

    for (int i=0;i<4;i++)
    {
        Gam::gamInit(&array[i]);
        Gam::gamInit(&arrayY[i]);
    }
}
void testtool::showResponse(const QString &s)
{

    ui->lb_makrresult->setText(s);
}

void testtool::processError(const QString &s)
{

    ui->lb_makrresult->setText(s);
}

void testtool::processTimeout(const QString &s)
{

    ui->lb_makrresult->setText(s);
}

void testtool::on_btn_scan_clicked()
{
    QString sx1,sx2,sx3,sx4;
    QString sy1,sy2,sy3,sy4;

    sx1 = ui->te_x->toPlainText();
    sx2 = ui->te_x_2->toPlainText();
    sx3 = ui->te_x_3->toPlainText();
    sx4 = ui->te_x_4->toPlainText();
    sy1 = ui->te_y->toPlainText();
    sy2 = ui->te_y_2->toPlainText();
    sy3 = ui->te_y_3->toPlainText();
    sy4 = ui->te_y_4->toPlainText();



    bool bxOK = false;
    bool byOK = false;
    int i = 0;

    if (sx1 != "" && sy1 != "")
    {
        array[i].x =sx1.toInt(&bxOK);
        array[i].y =sy1.toInt(&byOK);
        if (bxOK && byOK)
            i++;
    }

    if (sx2 != "" && sy2 != "")
    {
        array[i].x =sx2.toInt(&bxOK);
        array[i].y =sy2.toInt(&byOK);
        if (bxOK && byOK)
            i++;
    }
    if (sx3 != "" && sy3 != "")
    {
        array[i].x =sx3.toInt(&bxOK);
        array[i].y =sy3.toInt(&byOK);
        if (bxOK && byOK)
            i++;
    }
    if (sx4 != "" && sy4 != "")
    {
        array[i].x =sx4.toInt(&bxOK);
        array[i].y =sy4.toInt(&byOK);
        if (bxOK && byOK)
            i++;
    }

    if (i<2)
    {
        ui->lb_makrresult->setText(QString::fromLocal8Bit("请输入至少两个坐标"));
        return;
    }

    GamStu* gamEnable = Gam::getGam(REG_SEND_ENABLE_ADDR,1);
    if (gamEnable == NULL)
    {
        ui->lb_makrresult->setText(QString::fromLocal8Bit("get Gam fail"));
        return;
    }

    GamStu* gamNum = Gam::getGam(REG_SEND_NUM_ADDR,i);
    if (gamNum == NULL)
    {
        ui->lb_makrresult->setText(QString::fromLocal8Bit("get Gam fail"));
        return;
    }

    GamStu* gamStart = Gam::getGam(REG_SEND_START_ADDR,1);
    if (gamStart == NULL)
    {
        ui->lb_makrresult->setText(QString::fromLocal8Bit("get Gam fail"));
        return;
    }

    quint64 nlen = sizeof(GamStu) * i;

    quint32 ngamlen = sizeof(GamStu);
    gInput.resize(nlen + 3*ngamlen);
    memcpy(gInput.data(),gamEnable,ngamlen);
    memcpy(gInput.data()+ngamlen,gamNum,ngamlen);
    memcpy(gInput.data()+ngamlen,&array,nlen);
    memcpy(gInput.data()+nlen,&gamStart,ngamlen);

    QString currentPortName;
    currentPortName = ui->cb_serialport->currentText();

    thread.startMark(currentPortName,gInput);

    free(gamEnable);
    free(gamNum);
    free(gamStart);

}


void testtool::on_btInit_clicked()
{
    QString currentPortName;
    QLOG_INFO() << "on_btInit_clicked started";

    currentPortName = ui->cb_serialport->currentText();

    if (!tgam.sendCheck(currentPortName))
        return;
}

void testtool::on_btreadfile_clicked()
{
    Plt plt;
    plt.analyze("circle.plt");
}
