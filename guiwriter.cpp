#include <QMessageBox>

#include "guiwriter.h"

GUIWriter::GUIWriter(Severity::SeverityType severity, QWidget* parent)
    : LogWriter( severity ) {
  parent_ = parent;
}

GUIWriter::~GUIWriter() {
}

void GUIWriter::writeMessage(const Severity::SeverityType severity,
                             const QString& message ) throw() {
  if (severity <= min_severity_) {
    switch (severity) {
      case Severity::DEBUG:
        QMessageBox::information(parent_, "Debug Message", message);
        break;
      case Severity::INFO:
        QMessageBox::information(parent_, "Information", message);
        break;
      case Severity::WARNING:
        QMessageBox::warning(parent_, "Warning", message);
        break;
      case Severity::ERROR:
        QMessageBox::critical(parent_, "Error", message);
        break;
      default:
        QString err_msg =
            QString("Invalid severity (%1) with message \"%2\"").arg(Severity::toStr(severity)).arg(message);
        QMessageBox::critical(parent_, "Error", err_msg);
    }
  }
}
