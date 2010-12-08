#include <iostream>
#include <iomanip>
#include <ctime>

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

void cConsoleWriter::writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) throw()
{
    if( p_enSeverity <= m_enMinSeverity )
    {
        time_t     ttTime;
        struct tm *poTm;
        time( &ttTime );
        poTm = localtime( &ttTime );

        cerr << setw(2) << setfill('0') << poTm->tm_mday << ".";
        cerr << setw(2) << setfill('0') << poTm->tm_mon + 1 << ".";
        cerr << poTm->tm_year + 1900 << " ";
        cerr << setw(2) << setfill('0') << poTm->tm_hour << ":";
        cerr << setw(2) << setfill('0') << poTm->tm_min << ":";
        cerr << setw(2) << setfill('0') << poTm->tm_sec << " ";
        cerr << cSeverity::toStr( p_enSeverity ) << " " << p_stMessage << endl;
    }
}
