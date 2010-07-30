#ifndef LOGGER_H
#define LOGGER_H

#include "logwriter.h"
#include "severity.h"
#include <vector>

using namespace std;

class cLogger
{
public:
    cLogger() throw();
    ~cLogger() throw();

    void registerWriter( cLogWriter* p_poWriter ) throw();

    cLogger &operator <<( const cSeverity::teSeverity p_enSev ) {
        m_enSeverity = p_enSev;
        return *this;
    }

private:
    vector<cLogWriter*>    m_veWriters;
    cSeverity::teSeverity  m_enSeverity;
};

#endif
