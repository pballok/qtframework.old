#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <string>

using namespace std;

class cLogWriter
{
public:
    cLogWriter() throw() { };
    virtual ~cLogWriter() throw() { };

    virtual void writeMessage( const string &p_stMessage ) const throw() = 0;
};

#endif
