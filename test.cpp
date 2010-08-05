#include <QApplication>

#include "logger.h"
#include "consolewriter.h"

int main( int argc, char* argv[] )
{
    QApplication  apMainApp( argc, argv );

    cConsoleWriter  obConsoleWriter;
    cLogger         obLogger;

    obLogger.registerWriter( &obConsoleWriter );

    obLogger << cSeverity::DEBUG;

    return 0;
}

