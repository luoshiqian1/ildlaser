#ifndef LOG_H
#define LOG_H


#include "log.h"
#include <QLibrary>
#include <iostream>
#include <QCoreApplication>
#include <QDir>

class Log
{
public:
    Log();
    ~Log();
    void initLogger();
};

#endif // LOG_H
