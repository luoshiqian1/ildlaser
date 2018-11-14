#ifndef TESTTOOL_H
#define TESTTOOL_H

#include <QDialog>
#include "common.h"

namespace Ui {
class testtool;
}

class testtool : public QDialog
{
    Q_OBJECT

public:
    explicit testtool(QWidget *parent = 0);
    ~testtool();

private slots:
    void on_btn_scan_clicked();

private:
    Ui::testtool *ui;
};

#endif // TESTTOOL_H
