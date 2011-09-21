#include "logger.h"

using namespace std;

void cLogger::registerWriter( cLogWriter* p_poWriter ) throw()
{
    m_veWriters.push_back( p_poWriter );
}

void cLogger::writeMessage( const cSeverity::teSeverity p_enSeverity,
                            const string &p_stMessage )
{
    for( tiWriters  itWriters = m_veWriters.begin(); itWriters != m_veWriters.end(); itWriters++ )
    {
        (*itWriters)->writeMessage( p_enSeverity, p_stMessage );
    }
}
