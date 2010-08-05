#include "logger.h"
#include <iostream>

cLogger::cLogger() throw()
{
    cout << "cLogger::cLogger() called" << endl;
    m_enSeverity = cSeverity::MIN;
}

cLogger::cLogger( const cSeverity::teSeverity p_enSev, const cLogger *p_poOrigLogger ) throw()
    :m_veWriters( p_poOrigLogger->m_veWriters ),
     m_enSeverity( p_enSev )
{
    cout << "cLogger::cLogger( " << cSeverity::toStr( m_enSeverity ) << " ) called" << endl;
}

cLogger::~cLogger() throw()
{
    cout << "cLogger::~cLogger( " << cSeverity::toStr( m_enSeverity ) << " ) called" << endl;
}

void cLogger::registerWriter( cLogWriter* p_poWriter ) throw()
{
    cout << "cLogger::registerWriter() called" << endl;
    m_veWriters.push_back( p_poWriter );
}
