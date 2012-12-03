#ifndef SEVERITY_H
#define SEVERITY_H

#include <QString>

class Severity {
 public:
  enum SeverityType {
    MIN = 0,
    NONE,
    ERROR,
    WARNING,
    INFO,
    DEBUG,
    MAX
  };

  static QString toStr(SeverityType severity) {
    switch (severity) {
      case NONE:    return QString("NONE");    break;
      case ERROR:   return QString("ERROR");   break;
      case WARNING: return QString("WARNING"); break;
      case INFO:    return QString("INFO");    break;
      case DEBUG:   return QString("DEBUG");   break;
      default:      return QString("INVALID");
    }
  }

  static SeverityType fromStr(const QString& severity) {
    if (severity == "NONE")         return NONE;
    else if (severity == "ERROR")   return ERROR;
    else if (severity == "WARNING") return WARNING;
    else if (severity == "INFO")    return INFO;
    else if (severity == "DEBUG")   return DEBUG;
    else                            return MIN;
  }

 private:
  Severity() {}
};

#endif // SEVERITY_H
