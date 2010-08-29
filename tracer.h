#ifndef TRACER_H
#define TRACER_H

#include <string>
#include <sstream>

#include "logger.h"

class cTracer
{
public:
    static unsigned int m_uiIndent;

    cTracer( cLogger* p_poLogger, const std::string &p_stFuncName, const std::string &p_stInParams = "" );
    ~cTracer();

    cTracer &operator <<( const int p_inParam ) {
        m_ssOutParams << p_inParam;
        return *this;
    }
    cTracer &operator <<( const std::string &p_stParam ) {
        m_ssOutParams << p_stParam;
        return *this;
    }

private:
    cLogger*           m_poLogger;
    std::string        m_stFuncName;
    std::stringstream  m_ssOutParams;
};

#endif
