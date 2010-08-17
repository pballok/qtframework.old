#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include "severity.h"

using namespace std;

class cLogger;

class cLogMessage
{
public:
    cLogMessage();
    cLogMessage( const cSeverity::teSeverity p_enSev, cLogger *p_poLogger ) throw();
    ~cLogMessage();

private:
    cSeverity::teSeverity  m_enSeverity;
    cLogger               *m_poLogger;
};

#endif // LOGMESSAGE_H
