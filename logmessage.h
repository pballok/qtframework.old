#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <QTextStream>

#include "severity.h"

class LogMessage {
 public:
  enum LoggerManip {
    MIN = 0,
    EOM,
    CLEAR,
    MAX
  };

  LogMessage();
  LogMessage(const Severity::SeverityType severity);
  LogMessage(const LogMessage& orig_message);
  ~LogMessage();

  template<typename T>
  LogMessage& operator<<(const T param) {
    message_stream_ << param;
    return *this;
  }

  LogMessage &operator<<(const LoggerManip manipulator);

 private:
  Severity::SeverityType severity_;
  QString                message_;
  QTextStream            message_stream_;
};

#endif // LOGMESSAGE_H
