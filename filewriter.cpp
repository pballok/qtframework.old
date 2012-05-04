#include <ctime>
#include <sstream>
#include <iomanip>

#include "filewriter.h"

using namespace std;

cFileWriter::cFileWriter() throw() : cLogWriter()
{
}

cFileWriter::cFileWriter( cSeverity::teSeverity p_enSev,
                          const string p_stFileName,
                          const teFileMode p_enMode  ) throw() : cLogWriter( p_enSev )
{
    switch( p_enMode )
    {
        case BACKUP:
        {
            ifstream ifOriginalFile;
            ifOriginalFile.open( p_stFileName.c_str() );
            if( ifOriginalFile.is_open() )
            {
                time_t ttRawTime = time( NULL );
                struct tm *poTm = localtime( &ttRawTime );
                ostringstream  ssTimeStamp;

                ssTimeStamp << setw(2) << setfill('0') << poTm->tm_mday;
                ssTimeStamp << setw(2) << setfill('0') << poTm->tm_mon + 1;
                ssTimeStamp << poTm->tm_year+1900;

                ssTimeStamp << "_";
                ssTimeStamp << setw(2) << setfill('0') << poTm->tm_hour;
                ssTimeStamp << setw(2) << setfill('0') << poTm->tm_min;
                ssTimeStamp << setw(2) << setfill('0') << poTm->tm_sec;
                ssTimeStamp << "_";

                size_t inLastSlash = p_stFileName.find_last_of( '/' );
                if( inLastSlash == string::npos ) inLastSlash = p_stFileName.find_last_of( '\\' );
                if( inLastSlash == string::npos ) inLastSlash = 0;
                else inLastSlash++;
                string stBackupFileName = p_stFileName;
                stBackupFileName.insert( inLastSlash, ssTimeStamp.str() );

                ofstream ofBackupFile;
                ofBackupFile.open( stBackupFileName.c_str() );
                if( ofBackupFile.is_open() )
                {
                    ofBackupFile << ifOriginalFile.rdbuf();
                    ofBackupFile.close();
                }

                ifOriginalFile.close();
            }
            /* No break here because BACKUP continues with same functionality as
             * OVERWRITE */
        }
        case OVERWRITE:
            m_ofLogFile.open( p_stFileName.c_str(), ios_base::out | ios_base::trunc );
            break;
        default:  /* APPEND is same as default */
            m_ofLogFile.open( p_stFileName.c_str(), ios_base::out | ios_base::app );
    }
}

cFileWriter::~cFileWriter() throw()
{
    m_ofLogFile.close();
}

void cFileWriter::writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) throw()
{
    if( p_enSeverity <= m_enMinSeverity )
    {
        time_t     ttTime = time( NULL );
        struct tm *poTm = localtime( &ttTime );

        m_ofLogFile << setw(2) << setfill('0') << poTm->tm_mday << ".";
        m_ofLogFile << setw(2) << setfill('0') << poTm->tm_mon + 1 << ".";
        m_ofLogFile << poTm->tm_year + 1900 << " ";
        m_ofLogFile << setw(2) << setfill('0') << poTm->tm_hour << ":";
        m_ofLogFile << setw(2) << setfill('0') << poTm->tm_min << ":";
        m_ofLogFile << setw(2) << setfill('0') << poTm->tm_sec << " ";
        m_ofLogFile << cSeverity::toStr( p_enSeverity ) << " " << p_stMessage << endl;
    }
}
