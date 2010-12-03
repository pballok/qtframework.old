#ifndef SEVEXCEPTION_H
#define SEVEXCEPTION_H

#include <exception>
#include <string>

#include "severity.h"

class cSevException : public std::exception
{
public:
    cSevException( const cSeverity::teSeverity  p_enSev,
                   const std::string           &p_stMsg ) throw ()
        : m_enSeverity( p_enSev ), m_stMsg( p_stMsg ) { }
    virtual ~cSevException() throw() { }

    cSeverity::teSeverity severity() const throw() { return m_enSeverity; }
    virtual const char* what() const throw() { return m_stMsg.c_str(); }

private:
    cSeverity::teSeverity  m_enSeverity;
    std::string            m_stMsg;
};

#endif

