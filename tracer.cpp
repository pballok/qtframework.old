#include "severity.h"
#include "tracer.h"
#include "logger.h"

using namespace std;

unsigned int cTracer::m_uiIndent = 0;

cTracer::cTracer( const string &p_stFuncName,
                  const string &p_stInParams )
        : m_stFuncName( p_stFuncName )
{
    string  stMessage( m_uiIndent++, ' ');
    stMessage += p_stFuncName;
    stMessage += "( ";
    stMessage += p_stInParams;
    stMessage += " ) >";

    tgLogger::instance().writeMessage( cSeverity::DEBUG, stMessage );
}

cTracer::~cTracer()
{
    string stMessage( --m_uiIndent, ' ' );
    stMessage += m_stFuncName;
    stMessage += "( ";
    stMessage += m_ssOutParams.str();
    stMessage += " ) <";

    tgLogger::instance().writeMessage( cSeverity::DEBUG, stMessage );
}
