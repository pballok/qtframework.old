#include <QApplication>

#include "logger.h"
#include "consolewriter.h"

int main( int argc, char* argv[] )
{
    QApplication  apMainApp( argc, argv );

    cLogger         obLogger;

    cConsoleWriter  obConsoleWriter( cSeverity::DEBUG );
    obLogger.registerWriter( &obConsoleWriter );

    obLogger << cSeverity::DEBUG << "This is a DEBUG message" << cLogMessage::EOM;

    return 0;
}

