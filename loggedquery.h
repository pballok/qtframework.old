#ifndef LOGGEDQUERY_H
#define LOGGEDQUERY_H

#include <QSqlQuery>

class QString;
class QSqlResult;
class QSqlDatabase;

class LoggedQuery : public QSqlQuery {
 public:
  LoggedQuery(QSqlResult* result) : QSqlQuery(result) {}
  LoggedQuery(const QString& query = QString(),
              QSqlDatabase db = QSqlDatabase()) : QSqlQuery(query, db) {}
  LoggedQuery(QSqlDatabase db) : QSqlQuery(db) {}
  LoggedQuery(const LoggedQuery& other) : QSqlQuery(other) {}
  virtual ~LoggedQuery() {}

  bool exec(const QString& query);
};

#endif
