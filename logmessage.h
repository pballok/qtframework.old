#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <string>
#include <sstream>

#include "severity.h"

class cLogger;

class cLogMessage
{
public:
    enum teLoggerManip
    {
        MIN = 0,
        EOM,
        CLEAR,
        MAX
    };

    cLogMessage();
    cLogMessage( const cLogMessage &p_obOrigMessage );
    cLogMessage( const cSeverity::teSeverity p_enSev, cLogger *p_poLogger ) throw();
    ~cLogMessage();

    cLogMessage &operator <<( const int p_inParam ) {
        m_ssMessage << p_inParam;
        return *this;
    }
    cLogMessage &operator <<( const std::string p_stParam ) {
        m_ssMessage << p_stParam;
        return *this;
    }
    cLogMessage &operator <<( const teLoggerManip p_enManip );

private:
    cSeverity::teSeverity  m_enSeverity;
    cLogger               *m_poLogger;
    std::stringstream      m_ssMessage;
};

#endif // LOGMESSAGE_H
