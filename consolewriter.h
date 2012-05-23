#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "logwriter.h"

class ConsoleWriter : public LogWriter {
 public:
  ConsoleWriter(const Severity::SeverityType severity) : LogWriter(severity) {}
  virtual ~ConsoleWriter() {}

  virtual void writeMessage(const Severity::SeverityType severity,
                            const QString& message ) throw();

 protected:
  ConsoleWriter() {}
};

#endif
