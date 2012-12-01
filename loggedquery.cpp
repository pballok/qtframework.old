#include <QSqlError>

#include <tracer.h>
#include <logger.h>

#include "loggedquery.h"

bool LoggedQuery::exec(const QString& query) {
  if (isActive())
    clear();
  bool result = QSqlQuery::exec(query);
  logQuery();
  return result;
}

bool LoggedQuery::exec() {
  bool result = QSqlQuery::exec();
  logQuery();
  return result;
}

void LoggedQuery::logQuery() const {
  Tracer tracer("LoggedQuery::exec", lastQuery());

  if (isActive()) {
    if (isSelect()) {
      tracer << "Returned rows: " << size();
    } else {
      tracer << "Rows affected: " << numRowsAffected();
    }
  } else {
    Logger::instance() << Severity::ERROR << "SQL returned with error: \""
                       << lastError().text() << "\"";
  }
}
