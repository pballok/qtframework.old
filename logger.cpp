#include "logger.h"
#include <iostream>

cLogger::cLogger() throw()
{
    cout << "cLogger::cLogger() called" << endl;
}

cLogger::~cLogger() throw()
{
    cout << "cLogger::~cLogger() called" << endl;
}

void cLogger::registerWriter( cLogWriter* p_poWriter ) throw()
{
    cout << "cLogger::registerWriter() called" << endl;
    m_veWriters.push_back( p_poWriter );
}
