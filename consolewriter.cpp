#include "consolewriter.h"

#include <iostream>

cConsoleWriter::cConsoleWriter() throw() : cLogWriter()
{
}

cConsoleWriter::~cConsoleWriter() throw()
{
}

void cConsoleWriter::writeMessage( const string &p_stMessage ) const throw()
{
    cerr << p_stMessage << endl;
}
