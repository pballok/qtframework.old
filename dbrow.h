#ifndef DBROW_H
#define DBROW_H

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QVariant>

class DBRow {
 public:
  DBRow(const QString& table);
  DBRow(const QString& table, const unsigned int id);
  ~DBRow() {}

  void createNew();
  bool load(const unsigned int id);

 protected:
  QVariant value(const QString& column);
  bool setValue(const QString& column, const QVariant& value);

 private:
  void init();

  QSqlTableModel model_;
  QSqlRecord     record_;
  QString        tableName_;
  bool           modified_;
};

#endif // DBROW_H
