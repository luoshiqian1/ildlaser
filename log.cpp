#include "log.h"
#include "qslog/QsLog.h"
#include "qslog/QsLogDest.h"


Log::Log()
{
    initLogger();
}
Log::~Log()
{
    QsLogging::Logger::destroyInstance();
}

void myLogFunction(const QString &message, QsLogging::Level level)
{
    std::cout << "From log function: " << qPrintable(message) << " " << static_cast<int>(level)
              << std::endl;
}

void Log::initLogger()
{

    using namespace QsLogging;


    // 1. init the logging mechanism
    Logger& logger = Logger::instance();

    logger.setLoggingLevel(QsLogging::TraceLevel);


    //ÉèÖÃlogÎ»ÖÃ
    const QString sLogPath(QDir(QCoreApplication::applicationDirPath()).filePath("log.txt"));


    // 2. add two destinations
    DestinationPtr fileDestination(DestinationFactory::MakeFileDestination(
      sLogPath, EnableLogRotation, MaxSizeBytes(512), MaxOldLogCount(2)));

    DestinationPtr debugDestination(DestinationFactory::MakeDebugOutputDestination());
    DestinationPtr functorDestination(DestinationFactory::MakeFunctorDestination(&myLogFunction));


    logger.addDestination(debugDestination);
    logger.addDestination(fileDestination);
    logger.addDestination(functorDestination);

    QLOG_INFO() << "Program started";

/*
    // 3. start logging
    QLOG_INFO() << "Program started";
    QLOG_INFO() << "Built with Qt" << QT_VERSION_STR << "running on" << qVersion();

    QLOG_TRACE() << "Here's a" << QString::fromUtf8("trace") << "message";
    QLOG_DEBUG() << "Here's a" << static_cast<int>(QsLogging::DebugLevel) << "message";
    QLOG_WARN()  << "Uh-oh!";
    QLOG_ERROR() << "An error has occurred";

    QLOG_FATAL() << "Fatal error!";
*/

}



