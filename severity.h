#ifndef SEVERITY_H
#define SEVERITY_H

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

  static const char *toStr(SeverityType severity) {
    switch (severity) {
      case NONE:    return "NONE";    break;
      case ERROR:   return "ERROR";   break;
      case WARNING: return "WARNING"; break;
      case INFO:    return "INFO";    break;
      case DEBUG:   return "DEBUG";   break;
      default:      return "INVALID";
    }
  }

 private:
  Severity() {}
};

#endif // SEVERITY_H
