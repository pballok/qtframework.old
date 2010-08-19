#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <string>

class cLogWriter
{
public:
    cLogWriter() throw() { };
    virtual ~cLogWriter() throw() { };

    virtual void writeMessage( const std::string &p_stMessage ) const throw() = 0;
};

#endif
