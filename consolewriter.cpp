#include <iostream>

#include "consolewriter.h"

using namespace std;

cConsoleWriter::cConsoleWriter() throw() : cLogWriter()
{
}

cConsoleWriter::cConsoleWriter( cSeverity::teSeverity p_enSev ) throw() : cLogWriter( p_enSev )
{
}

cConsoleWriter::~cConsoleWriter() throw()
{
}

void cConsoleWriter::writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) const throw()
{
    if( p_enSeverity <= m_enMinSeverity ) cerr << p_stMessage << endl;
}
