#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "logwriter.h"

class cConsoleWriter : public cLogWriter
{
public:
    cConsoleWriter() throw();
    virtual ~cConsoleWriter() throw();

    virtual void writeMessage( const string &p_stMessage ) const throw();
};

#endif
