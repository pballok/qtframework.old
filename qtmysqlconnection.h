#ifndef CQTMYSQLCONNECTION_H
#define CQTMYSQLCONNECTION_H

#include <QtSql>
#include <QString>
#include <logger.h>
#include <sevexception.h>

class cQTMySQLConnection
{
public:
    cQTMySQLConnection( cLogger *p_poLogger );
    ~cQTMySQLConnection();

    void open( void )                                         throw( cSevException );
    void close( void )                                        throw( cSevException );
    void executeQuery( const QString &p_qsQuery )             throw( cSevException );
    QSqlQuery* executeQTQuery( const QString &p_qsQuery )     throw( cSevException );

    void setHostName( const QString &p_qsHost )               throw();
    QString  hostName( void )                                 throw();
    void setDatabaseName( const QString &p_qsDB )             throw();
    QString  databaseName( void )                             throw();
    void setUserName( const QString &p_qsUser )               throw();
    QString userName( void )                                  throw();
    void setPassword( const QString &p_qsPwd )                throw();
    QString password( void )                                  throw();

private:
    cLogger      *m_poLogger;
    QSqlDatabase *m_poDB;
    bool          m_boOpen;
};

#endif
