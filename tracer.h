#ifndef TRACER_H
#define TRACER_H

#include <string>
#include <sstream>

class cTracer
{
public:
    static unsigned int m_uiIndent;

    cTracer( const std::string &p_stFuncName, const std::string &p_stInParams = "" );
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
    std::string        m_stFuncName;
    std::stringstream  m_ssOutParams;
};

#endif
