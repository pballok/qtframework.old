#include <QSqlError>

#include <tracer.h>
#include <logger.h>

#include "loggedquery.h"

bool LoggedQuery::exec(const QString& query) {
  bool result = QSqlQuery::exec(query);
  logQuery(result);
  return result;
}

bool LoggedQuery::exec() {
  bool result = QSqlQuery::exec();
  logQuery(result);
  return result;
}

void LoggedQuery::logQuery(bool success) const {
  Tracer tracer("LoggedQuery::exec", lastQuery());

  if (success) {
    if (isSelect()) {
      tracer << "Returned rows: " << size();
    } else {
      tracer << "Rows affected: " << numRowsAffected();
    }
  } else {
    Logger::instance() << Severity::ERROR << "MySQL returned with error: \""
                       << lastError().text() << "\"";
  }
}
