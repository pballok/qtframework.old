#include <QSqlError>

#include <tracer.h>
#include <logger.h>

#include "loggedquery.h"

bool LoggedQuery::exec(const QString& query) {
  Tracer tracer("LoggedQuery::exec", query);

  bool result = QSqlQuery::exec(query);
  if (result) {
    if (isSelect()) {
      tracer << "Returned rows: " << size();
    } else {
      tracer << "Rows affected: " << numRowsAffected();
    }
  } else {
    Logger::instance() << Severity::ERROR << "MySQL returned with error: \""
                       << lastError().text() << "\"";
  }

  return result;
}
