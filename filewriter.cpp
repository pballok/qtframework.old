#include "filewriter.h"

cFileWriter::cFileWriter() throw() : cLogWriter()
{
}

cFileWriter::cFileWriter( cSeverity::teSeverity p_enSev ) throw() : cLogWriter( p_enSev )
{
}

cFileWriter::~cFileWriter() throw()
{
}

void cFileWriter::writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) const throw()
{
    if( p_enSeverity <= m_enMinSeverity )
    {
    }
}
