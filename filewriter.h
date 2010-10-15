#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "logwriter.h"

class cFileWriter : public cLogWriter
{
public:
    cFileWriter() throw();
    cFileWriter( cSeverity::teSeverity p_enSev ) throw();
    virtual ~cFileWriter() throw();

    virtual void writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) const throw();
};

#endif // FILEWRITER_H
