#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include "logwriter.h"

class cFileWriter : public cLogWriter
{
public:
    enum teFileMode
    {
        MIN = 0,
        BACKUP,
        OVERWRITE,
        APPEND,
        MAX
    };

    cFileWriter() throw();
    cFileWriter( cSeverity::teSeverity p_enSev, const std::string p_stFileName,
                 const teFileMode p_enMode = APPEND ) throw();
    virtual ~cFileWriter() throw();

    virtual void writeMessage( const cSeverity::teSeverity p_enSeverity,
                               const std::string &p_stMessage ) throw();

private:
    std::ofstream m_ofLogFile;
};

#endif // FILEWRITER_H
