#include "qtmysqlconnection.h"

cQTMySQLConnection::cQTMySQLConnection( cLogger *p_poLogger )
{
    m_poLogger = p_poLogger;
    m_poDB     = new QSqlDatabase( QSqlDatabase::addDatabase( "QMYSQL" ) );
    m_boOpen   = false;
}

cQTMySQLConnection::~cQTMySQLConnection()
{
    delete m_poDB;
}

void cQTMySQLConnection::open( void ) throw( cSevException )
{
    if( m_boOpen ) close();

    if( m_poDB->open() )
    {
        m_boOpen = true;
    }
    else
    {
        throw cSevException( cSeverity::ERROR,
                "Error opening database: " + m_poDB->lastError().text().toStdString() );
    }
}

void cQTMySQLConnection::close( void ) throw( cSevException )
{
    if( m_boOpen )
    {
        m_poDB->close();
        m_boOpen = false;
    }
}

void cQTMySQLConnection::executeQuery( const QString &p_qsQuery )
                         throw( cSevException )
{
    if( !m_boOpen )
        throw cSevException( cSeverity::ERROR,
                "Error executing query: Database is not open" );

    m_poLogger->writeMessage( cSeverity::DEBUG, p_qsQuery.toStdString() );

    QSqlQuery  obQuery;
    if( !obQuery.exec( p_qsQuery ) )
    {
        throw cSevException( cSeverity::ERROR,
                "Error executing query: " + obQuery.lastError().text().toStdString() );
    }
}

QSqlQuery* cQTMySQLConnection::executeQTQuery( const QString &p_qsQuery )
                               throw( cSevException )
{
    m_poLogger->writeMessage( cSeverity::DEBUG, p_qsQuery.toStdString() );

    if( !m_boOpen )
        throw cSevException( cSeverity::ERROR,
                "Error executing query: Database is not open" );

    QSqlQuery*  poQuery = new QSqlQuery;
    if( !poQuery->exec( p_qsQuery ) )
    {
        QString  qsError = poQuery->lastError().text();
        delete poQuery;

        throw cSevException( cSeverity::ERROR,
                "Error executing query: " + qsError.toStdString() );
    }

    return poQuery;
}

void cQTMySQLConnection::setHostName( const QString &p_qsHost ) throw()
/* This function sets the Host Name for the MySQL database access.
 * If the database is already open, it will be closed first. */
{
    if( hostName() != p_qsHost )
    {
        if( m_boOpen ) close();
        m_poDB->setHostName( p_qsHost );
    }
}

QString cQTMySQLConnection::hostName( void ) throw()
{
    return m_poDB->hostName();
}

void cQTMySQLConnection::setDatabaseName( const QString &p_qsDB ) throw()
/* This function sets the Database Name for the MySQL database access.
 * If the database is already open, it will be closed first. */
{
    if( databaseName() != p_qsDB )
    {
        if( m_boOpen ) close();
        m_poDB->setDatabaseName( p_qsDB );
    }
}

QString cQTMySQLConnection::databaseName( void ) throw()
{
    return m_poDB->databaseName();
}

void cQTMySQLConnection::setUserName( const QString &p_qsUser ) throw()
/* This function sets the User Name for the MySQL database access.
 * If the database is already open, it will be closed first. */
{
    if( userName() != p_qsUser )
    {
        if( m_boOpen ) close();
        m_poDB->setUserName( p_qsUser );
    }
}

QString cQTMySQLConnection::userName( void ) throw()
{
    return m_poDB->userName();
}

void cQTMySQLConnection::setPassword( const QString &p_qsPwd ) throw()
/* This function sets the Password for the MySQL database access.
 * If the database is already open, it will be closed first. */
{
    if( password() != p_qsPwd )
    {
        if( m_boOpen ) close();
        m_poDB->setPassword( p_qsPwd );
    }
}

QString cQTMySQLConnection::password( void ) throw()
{
    return m_poDB->password();
}
