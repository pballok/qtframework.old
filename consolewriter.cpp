#include <iostream>

#include "consolewriter.h"

using namespace std;

cConsoleWriter::cConsoleWriter() throw() : cLogWriter()
{
}

cConsoleWriter::~cConsoleWriter() throw()
{
}

void cConsoleWriter::writeMessage( const std::string &p_stMessage ) const throw()
{
    cerr << p_stMessage << endl;
}
