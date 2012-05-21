#ifndef GUIWRITER_H
#define GUIWRITER_H

#include <QWidget>
#include <QString>

#include "logwriter.h"

class GUIWriter : public LogWriter {
 public:
  GUIWriter(Severity::SeverityType severity, QWidget* parent = 0);
  virtual ~GUIWriter();

  virtual void writeMessage(const Severity::SeverityType severity,
                            const QString& message ) throw();

 protected:
  GUIWriter() : LogWriter() {}

 private:
  QWidget*  parent_;
};

#endif // GUIWRITER_H
