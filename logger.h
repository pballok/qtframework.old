#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

#include "logwriter.h"
#include "logmessage.h"
#include "severity.h"
#include "sevexception.h"

class cLogger;
class cLogger
{
public:
    cLogger() throw();
    ~cLogger() throw();

    void  registerWriter( cLogWriter* p_poWriter ) throw();
    void  writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage );

    inline cLogMessage operator <<( const cSeverity::teSeverity p_enSev ) {
        return cLogMessage( p_enSev, this );
    }

    cLogger &operator <<( const cSevException &p_obException ) {
        writeMessage( p_obException.severity(), p_obException.what() );
        return *this;
    }


private:
    typedef std::vector<cLogWriter*>   tvWriters;
    typedef tvWriters::const_iterator  tiWriters;

    tvWriters    m_veWriters;
};

#endif
