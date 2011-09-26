#include "preferences.h"

cPreferences::cPreferences()
{
    m_qsAppName   = "";
    m_qsVersion   = "";
    m_qsFileName  = "";
}

cPreferences::~cPreferences()
{
}

QString cPreferences::appName() const
{
    return m_qsAppName;
}

void cPreferences::setAppName( const QString &p_qsAppName )
{
    m_qsAppName  = p_qsAppName;
    m_qsFileName = QString( "./%1.ini" ).arg( p_qsAppName );
}

QString cPreferences::version() const
{
    return m_qsVersion;
}

void cPreferences::setVersion( const QString &p_qsVersion )
{
    m_qsVersion = p_qsVersion;
}

void cPreferences::load() throw(cSevException)
{
    QSettings obPrefFile( m_qsFileName, QSettings::IniFormat );
    if( obPrefFile.status() != QSettings::NoError )
    {
        throw cSevException( cSeverity::WARNING, QString( "Failed to open preferences file: %1" ).arg( m_qsFileName ).toStdString() );
    }

    readSettings( &obPrefFile );
}

void cPreferences::save() const throw(cSevException)
{
    QSettings obPrefFile( m_qsFileName, QSettings::IniFormat );
    if( obPrefFile.status() != QSettings::NoError )
    {
        throw cSevException( cSeverity::WARNING, QString( "Failed to write to preferences file: %1" ).arg( m_qsFileName ).toStdString() );
    }

    writeSettings( &obPrefFile );
}

void cPreferences::readSettings( const QSettings* )
{
}

void cPreferences::writeSettings( const QSettings* ) const
{
}
