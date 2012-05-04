#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QString>
#include <QSettings>

#include <guiwriter.h>
#include <filewriter.h>
#include <sevexception.h>

class cPreferences
{
public:
    cPreferences();
    ~cPreferences();

    QString                    appName() const;
    void                       setAppName( const QString &p_qsAppName );
    QString                    version() const;
    void                       setVersion( const QString &p_qsVersion );

    void                       load() throw(cSevException);
    void                       save() const throw(cSevException);

protected:

    QString                    m_qsAppName;
    QString                    m_qsVersion;
    QString                    m_qsFileName;

    virtual void               readSettings( QSettings *m_poSettingsFile ) = 0;
    virtual void               writeSettings( QSettings *m_poSettingsFile ) const = 0;
};

#endif
