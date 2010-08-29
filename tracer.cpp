#include "severity.h"
#include "tracer.h"

using namespace std;

unsigned int cTracer::m_uiIndent = 0;

cTracer::cTracer( cLogger* p_poLogger,
                  const string &p_stFuncName,
                  const string &p_stInParams )
        : m_poLogger( p_poLogger ),
          m_stFuncName( p_stFuncName )
{
    string  stMessage( m_uiIndent++, ' ');
    stMessage += p_stFuncName;
    stMessage += "( ";
    stMessage += p_stInParams;
    stMessage += " ) >";

    m_poLogger->writeMessage( cSeverity::DEBUG, stMessage );
}

cTracer::~cTracer()
{
    string stMessage( --m_uiIndent, ' ' );
    stMessage += m_stFuncName;
    stMessage += "( ";
    stMessage += m_ssOutParams.str();
    stMessage += " ) <";

    m_poLogger->writeMessage( cSeverity::DEBUG, stMessage );
}
