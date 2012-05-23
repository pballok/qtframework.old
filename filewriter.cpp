#include <QDateTime>

#include "filewriter.h"

FileWriter::FileWriter(const Severity::SeverityType severity,
                       const QString& file_name,
                       const FileMode file_mode) : LogWriter(severity)
{
  log_file_.setFileName(file_name);
  switch (file_mode) {
    case BACKUP: {
      if (log_file_.exists()) {
        QString timestamp =
            QDateTime::currentDateTime().toString("ddMMyyyy_hhmmss_");

        int last_slash_pos = file_name.lastIndexOf("/");
        if (last_slash_pos == -1) {
            last_slash_pos = file_name.lastIndexOf("\\");
        }
        if (last_slash_pos == -1) {
          last_slash_pos = 0;
        }
        else {
          ++last_slash_pos;
        }

        QString backup_file_name = file_name;
        backup_file_name.insert(last_slash_pos, timestamp);
        log_file_.copy(backup_file_name);
      }
      /* No break here because BACKUP continues with same functionality as
       * OVERWRITE */
    }
    case OVERWRITE: {
      log_file_.open(QIODevice::Truncate | QIODevice::WriteOnly |
                     QIODevice::Text);
      break;
    }
    case APPEND: {
      log_file_.open(QIODevice::Append | QIODevice::WriteOnly |
                     QIODevice::Text);
      break;
    }
    default: return;
  }
  log_stream_.setDevice(&log_file_);
}

FileWriter::~FileWriter() {
  log_file_.close();
}

void FileWriter::writeMessage(const Severity::SeverityType severity,
                              const QString& message) throw() {
  if (severity <= min_severity_) {
    QString timestamp =
        QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    log_stream_ << timestamp << " " << Severity::toStr(severity) << " "
                << message << endl;
  }
}
