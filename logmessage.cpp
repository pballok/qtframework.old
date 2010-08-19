#include "logmessage.h"
#include "logger.h"

cLogMessage::cLogMessage()
{
    m_enSeverity = cSeverity::MIN;
}


cLogMessage::cLogMessage( const cLogMessage &p_obOrigMessage )
{
    m_enSeverity = p_obOrigMessage.m_enSeverity;
    m_poLogger   = p_obOrigMessage.m_poLogger;
    m_ssMessage << p_obOrigMessage.m_ssMessage.rdbuf();
}

cLogMessage::cLogMessage( const cSeverity::teSeverity p_enSev, cLogger *p_poLogger ) throw()
    : m_enSeverity( p_enSev ),
      m_poLogger( p_poLogger )
{
}

cLogMessage::~cLogMessage()
{
//    if( m_ssMessage.str() != "" ) m_poLogger->writeMessage( m_enSeverity, m_ssMessage.str() );
}

cLogMessage &cLogMessage::operator <<( const teLoggerManip p_enManip ) {
    switch( p_enManip )
    {
        case EOM:
//            m_poLogger->writeMessage( m_enSeverity, m_ssMessage.str() );
            // There's no 'break' here because the EOM manipulator
            // needs to do a 'CLEAR' as well
        case CLEAR:
            m_ssMessage.str( "" );
            break;
        default: ;
    }
    return *this;
}
