#include <QApplication>

#include "logger.h"
#include "consolewriter.h"
#include "guiwriter.h"
#include "filewriter.h"
#include "tracer.h"

int main( int argc, char* argv[] )
{
    QApplication  apMainApp( argc, argv );

    cLogger         obLogger;

    cConsoleWriter  obConsoleWriter( cSeverity::DEBUG );
    obLogger.registerWriter( &obConsoleWriter );

    cGUIWriter  obGUIWriter( cSeverity::INFO );
    obLogger.registerWriter( &obGUIWriter );

    cFileWriter obFileWriter( cSeverity::INFO, "log/test.log", cFileWriter::BACKUP );
    obLogger.registerWriter( &obFileWriter );

    cTracer obTracer1( &obLogger, "This is the first TRACER message", "param" );

    obLogger << cSeverity::DEBUG << "This is a DEBUG message" << cLogMessage::EOM;

    obLogger << cSeverity::INFO << "This is an INFO message" << cLogMessage::EOM;

    obLogger << cSeverity::WARNING << "This is a WARNING message" << cLogMessage::EOM;

    obLogger << cSeverity::ERROR << "This is an ERROR message" << cLogMessage::EOM;

    cTracer obTracer2( &obLogger, "This is the second TRACER message", "param" );

    return 0;
}
