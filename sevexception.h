#ifndef SEVEXCEPTION_H
#define SEVEXCEPTION_H

#include <exception>
#include <string>
#include <QString>

#include "severity.h"

class SevException : public std::exception {
 public:
  SevException(const Severity::SeverityType severity,
               const std::string& message)
    : severity_(severity), message_(message) {}

  SevException(const Severity::SeverityType severity, const QString& message)
    : severity_(severity), message_(message.toStdString()) {}

  virtual ~SevException() throw() {}

  Severity::SeverityType severity() const throw() {
    return severity_;
  }

  virtual const char* what() const throw() {
    return message_.c_str();
  }

private:
    Severity::SeverityType severity_;
    std::string            message_;
};

#endif

