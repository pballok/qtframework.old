#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

#include "logwriter.h"
#include "logmessage.h"
#include "severity.h"
#include "sevexception.h"

class cLogger
{
public:
    inline static cLogger& instance()
    {
        static cLogger m_obInstance;
        return m_obInstance;
    }

    void  registerWriter( cLogWriter* p_poWriter ) throw();
    void  writeMessage( const cSeverity::teSeverity p_enSeverity,
                        const std::string &p_stMessage );

    inline cLogMessage operator <<( const cSeverity::teSeverity p_enSev )
    {
        return cLogMessage( p_enSev, this );
    }

    inline cLogger& operator <<( const cSevException &p_obException )
    {
        writeMessage( p_obException.severity(), p_obException.what() );
        return *this;
    }


private:
    inline explicit cLogger() throw() {}
    inline ~cLogger() throw() {}
    inline explicit cLogger( cLogger const& ) {}
    inline cLogger& operator =( cLogger const& ) { return *this; }

    typedef std::vector<cLogWriter*>   tvWriters;
    typedef tvWriters::const_iterator  tiWriters;

    tvWriters    m_veWriters;
};

#endif
