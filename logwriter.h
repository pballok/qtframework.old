#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <QString>

#include "severity.h"

class LogWriter {
 public:
  LogWriter(Severity::SeverityType severity) {
    min_severity_ = severity;
  }
  virtual ~LogWriter() {}

  Severity::SeverityType min_severity() const {
    return min_severity_;
  }

  void set_min_severity(const Severity::SeverityType severity) {
    min_severity_ = severity;
  }

  virtual void writeMessage(const Severity::SeverityType severity,
                            const QString& message) = 0;

protected:
  LogWriter() {
    min_severity_ = Severity::NONE;
  }

  Severity::SeverityType  min_severity_;
};

#endif
