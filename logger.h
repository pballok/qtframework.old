#ifndef LOGGER_H
#define LOGGER_H

#include "logwriter.h"
#include "severity.h"
#include <vector>

using namespace std;

class cLogger;
class cLogger
{
public:
    cLogger() throw();
    cLogger( const cSeverity::teSeverity p_enSev, const cLogger *p_poOrigLogger ) throw();
    ~cLogger() throw();

    void                   registerWriter( cLogWriter* p_poWriter ) throw();

    cLogger operator <<( const cSeverity::teSeverity p_enSev ) {
        return cLogger( p_enSev, this );
    }

private:
    vector<cLogWriter*>    m_veWriters;
    cSeverity::teSeverity  m_enSeverity;
};

#endif
