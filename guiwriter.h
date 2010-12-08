#ifndef GUIWRITER_H
#define GUIWRITER_H

#include <QWidget>

#include "logwriter.h"

class cGUIWriter : public cLogWriter
{
public:
    cGUIWriter() throw();
    cGUIWriter( cSeverity::teSeverity p_enSev, QWidget* p_poParent = 0 ) throw();
    virtual ~cGUIWriter() throw();

    virtual void writeMessage( const cSeverity::teSeverity p_enSeverity, const std::string &p_stMessage ) throw();

private:
    QWidget*  m_poParent;
};

#endif // GUIWRITER_H
