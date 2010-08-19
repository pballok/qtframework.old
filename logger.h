#ifndef LOGGER_H
#define LOGGER_H

#include <vector>

#include "logwriter.h"
#include "logmessage.h"
#include "severity.h"

class cLogger;
class cLogger
{
public:
    cLogger() throw();
    ~cLogger() throw();

    void                   registerWriter( cLogWriter* p_poWriter ) throw();

    inline cLogMessage operator <<( const cSeverity::teSeverity p_enSev ) {
        return cLogMessage( p_enSev, this );
    }

private:
    std::vector<cLogWriter*>    m_veWriters;
};

#endif
