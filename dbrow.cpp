#include <QSqlQuery>
#include <QSqlError>

#include <tracer.h>
#include <logger.h>

#include "dbrow.h"

DBRow::DBRow(const QString& table) : tableName_(table) {
  init();
}

DBRow::DBRow(const QString& table, const unsigned int id) : tableName_(table) {
  init();

  if (id) {
    load(id);
  } else {
    createNew();
  }
}

void DBRow::init() {
  model_.clear();
  model_.setTable(tableName_);
  model_.setEditStrategy(QSqlTableModel::OnManualSubmit);
  modified_ = false;
}

void DBRow::createNew() {
  Tracer tracer("DBRow::createNew",
                QString("table: %1").arg(model_.tableName()));
  init();
  record_ = model_.record();
}

bool DBRow::load(const unsigned int id) {
  Tracer tracer("DBRow::load",
                QString("table: %1 id: %2").arg(model_.tableName()).arg(id));
  init();
  model_.setFilter(QString("id=%1").arg(id));
  bool res = model_.select();
  Logger::instance() << Severity::DEBUG
                     << model_.query().lastQuery()
                     << LogMessage::EOM;
  if (res) {
    record_ = model_.record(0);
  } else {
    record_ = QSqlRecord();
    Logger::instance() << Severity::ERROR
                       << model_.lastError().text()
                       << LogMessage::EOM;
  }

  return res;
}
