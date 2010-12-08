#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <string>

#include "severity.h"

class cLogWriter
{
public:
    cLogWriter() throw() { m_enMinSeverity = cSeverity::NONE; }
    cLogWriter( cSeverity::teSeverity p_enSev ) { m_enMinSeverity = p_enSev; }
    virtual ~cLogWriter() throw() { }

    cSeverity::teSeverity  minSeverity() const throw() { return m_enMinSeverity; }
    void                   setMinSeverity( const cSeverity::teSeverity p_enSev ) { m_enMinSeverity = p_enSev; }

    virtual void writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) throw() = 0;

protected:
    cSeverity::teSeverity  m_enMinSeverity;
};

#endif
