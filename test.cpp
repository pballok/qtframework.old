#include "logger.h"
#include "consolewriter.h"

int main( int, char** )
{
    cConsoleWriter  obConsoleWriter;
    cLogger         obLogger;

    obLogger.registerWriter( &obConsoleWriter );

    obLogger << cSeverity::DEBUG;
}

