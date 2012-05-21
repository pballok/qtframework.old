#include <QDateTime>
#include <QString>

#include <iostream>
#include <iomanip>

#include "consolewriter.h"

using namespace std;

void ConsoleWriter::writeMessage(const Severity::SeverityType severity,
                                 const QString& message) throw() {
  if (severity <= min_severity_) {
    QString timestamp =
        QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    cerr << timestamp.toStdString() << " " << Severity::toStr(severity) << " "
         << message.toStdString() << endl;
  }
}
