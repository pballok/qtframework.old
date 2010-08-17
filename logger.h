#ifndef LOGGER_H
#define LOGGER_H

#include "logwriter.h"
#include "logmessage.h"
#include "severity.h"
#include <vector>

using namespace std;

class cLogger;
class cLogger
{
public:
    cLogger() throw();
    ~cLogger() throw();

    void                   registerWriter( cLogWriter* p_poWriter ) throw();

    cLogMessage operator <<( const cSeverity::teSeverity p_enSev ) {
        return cLogMessage( p_enSev, this );
    }

private:
    vector<cLogWriter*>    m_veWriters;
};

#endif
