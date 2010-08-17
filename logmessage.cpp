#include "logmessage.h"
#include <iostream>

cLogMessage::cLogMessage()
{
    cout << "cLogMessage::cLogMessage() called" << endl;
    m_enSeverity = cSeverity::MIN;
}

cLogMessage::cLogMessage( const cSeverity::teSeverity p_enSev, cLogger *p_poLogger ) throw()
    : m_enSeverity( p_enSev ),
      m_poLogger( p_poLogger )
{
    cout << "cLogMessage::cLogMessage( " << cSeverity::toStr( m_enSeverity ) << " ) called" << endl;
}

cLogMessage::~cLogMessage()
{
    cout << "cLogMessage::~cLogMessage( " << cSeverity::toStr( m_enSeverity ) << " ) called" << endl;
}
