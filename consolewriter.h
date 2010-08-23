#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "logwriter.h"

class cConsoleWriter : public cLogWriter
{
public:
    cConsoleWriter() throw();
    cConsoleWriter( cSeverity::teSeverity p_enSev ) throw();
    virtual ~cConsoleWriter() throw();

    virtual void writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) const throw();
};

#endif
