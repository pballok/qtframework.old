#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "logwriter.h"
#include "severity.h"

class FileWriter : public LogWriter {
 public:
  enum FileMode {
    MIN = 0,
    BACKUP,
    OVERWRITE,
    APPEND,
    MAX
  };

  FileWriter(const Severity::SeverityType severity,
             const QString& file_name,
             const FileMode file_mode = APPEND);
  virtual ~FileWriter();

  virtual void writeMessage(const Severity::SeverityType severity,
                            const QString& message ) throw();

 protected:
  FileWriter() : LogWriter() {}

 private:
  QFile       log_file_;
  QTextStream log_stream_;
};

#endif // FILEWRITER_H
