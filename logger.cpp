#include "logger.h"

cLogger::cLogger() throw()
{
}

cLogger::~cLogger() throw()
{
}

void cLogger::registerWriter( cLogWriter* p_poWriter ) throw()
{
    m_veWriters.push_back( p_poWriter );
}
