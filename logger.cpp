#include "logger.h"
#include <iostream>

cLogger::cLogger() throw()
{
    cout << "cLogger::cLogger() called" << endl;
    m_enSeverity = cSeverity::MIN;
}

cLogger::~cLogger() throw()
{
    cout << "cLogger::~cLogger() called" << endl;
}

void cLogger::registerWriter( cLogWriter* p_poWriter ) throw()
{
    m_veWriters.push_back( p_poWriter );
}


