#ifndef COMMON_H
#define COMMON_H

#include <QMdiSubWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMdiArea>
#include <QAction>
#include <QMenu>
#include <QApplication>
#include <QDesktopWidget>
#include <string.h>
#include "qslog/QsLog.h"
#include "qslog/QsLogDest.h"


#define REG_TEST_ADDR               0x000
#define REG_VERSION1_ADDR           0x004
#define REG_VERSION0_ADDR           0x008
#define REG_RESET_ADDR              0x010
#define REG_CONFIG_DATA_ADDR        0x014
#define REG_CONFIG_ADDRA_ADDR       0x018
#define REG_CONFIG_STU_ADDR         0x01C
#define REG_READBACK_ADDR           0x020
#define REG_READBACK_ADDRB_ADDR     0x024
#define REG_READBACK_DOUT_ADDR      0x028
#define REG_SEND_NUM_ADDR           0x030
#define REG_SEND_SPACE_ADDR         0x034
#define REG_SEND_OPENTIME_ADDR      0x038
#define REG_SEND_DONE_ADDR          0x040
#define REG_SEND_ENABLE_ADDR        0x044
#define REG_SEND_START_ADDR         0x048


#define HEADER0 0x3A
#define HEADER1 0x52
#define HEADER2 0x53

#define END0    0x0D
#define END1    0x0A

#define LRC_LEN   11

#define WAIT_TIMEOUT 3000

const int BAUD_RATE = 115200;

extern quint32 gnBaseAddr;                 // �ڴ����ַ

typedef struct {
    unsigned char header[3];        // ͷ������ 3A 52 53
    quint32 addr;                   // �Ĵ�����ַ
    union
    {
        quint32 ndata;                  // ����
        struct{
            quint16 y;
            quint16 x;
        };
    };

    unsigned char lrc;              // ͷ�����Ĵ������������
    unsigned char end[2];           // β������ 0D 0A
} GamStu;

typedef struct {
    qint16 x;                      // X����
    qint16 y;                      // Y����
} XY;

#endif // COMMON_H
