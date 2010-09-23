#include <QMessageBox>

#include "guiwriter.h"

cGUIWriter::cGUIWriter() throw() : cLogWriter()
{
}

cGUIWriter::cGUIWriter( cSeverity::teSeverity p_enSev, QWidget* p_poParent ) throw() : cLogWriter( p_enSev )
{
    m_poParent = p_poParent;
}

cGUIWriter::~cGUIWriter() throw()
{
}

void cGUIWriter::writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) const throw()
{
    if( p_enSeverity <= m_enMinSeverity )
    {
        switch( p_enSeverity )
        {
            case cSeverity::DEBUG:   QMessageBox::information( m_poParent, "Debug Message", QString::fromStdString( p_stMessage ) ); break;
            case cSeverity::INFO:    QMessageBox::information( m_poParent, "Information", QString::fromStdString( p_stMessage ) ); break;
            case cSeverity::WARNING: QMessageBox::warning( m_poParent, "Warning", QString::fromStdString( p_stMessage ) ); break;
            case cSeverity::ERROR:   QMessageBox::critical( m_poParent, "Error", QString::fromStdString( p_stMessage ) ); break;
            default: QMessageBox::critical( m_poParent, "Error", QString( "Invalid severity (%1) with message \"%2\"" ).arg( (int)p_enSeverity ).arg( QString::fromStdString( p_stMessage ) ) ); break;
        }
    }
}
