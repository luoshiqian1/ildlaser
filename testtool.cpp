#include "testtool.h"
#include "ui_testtool.h"


testtool::testtool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testtool)
{
    ui->setupUi(this);
}

testtool::~testtool()
{
    delete ui;
}

void testtool::on_btn_scan_clicked()
{
    QString sx1,sx2,sx3,sx4;
    QString sy1,sy2,sy3,sy4;
    QString sout;

    sx1 = ui->te_x->toPlainText();
    sx2 = ui->te_x_2->toPlainText();
    sx3 = ui->te_x_3->toPlainText();
    sx4 = ui->te_x_4->toPlainText();
    sy1 = ui->te_y->toPlainText();
    sy2 = ui->te_y_2->toPlainText();
    sy3 = ui->te_y_3->toPlainText();
    sy4 = ui->te_y_4->toPlainText();

    sout = QString("{(%1,%2),(%3,%4),(%5,%6),(%7,%8)}").arg(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);

    QMessageBox m(this);
    m.setWindowTitle("开始打标");
    m.setText(sout);
    m.exec();
}
