#include <string>

#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QStringList>

#include <logger.h>
#include <filewriter.h>

#include "frameworktest.h"

using namespace std;

void FrameworkTest::fileLogger()
{
  QString file_name_1 = "writertest_1.log";
  QFile log_file_1(file_name_1);
  QVERIFY(log_file_1.open(QIODevice::Truncate | QIODevice::WriteOnly
                                              | QIODevice::Text));
  QTextStream out(&log_file_1);
  out << "Old Text 01" << "\n";
  out << "Old Text 02" << "\n";
  log_file_1.close();

  QString file_name_2 = "writertest_2.log";
  QFile::remove(file_name_2);
  QVERIFY(log_file_1.copy(file_name_2));
  QFile log_file_2(file_name_2);

  QString file_name_3 = "writertest_3.log";
  QFile log_file_3(file_name_3);

  FileWriter file_writer_1(Severity::INFO, file_name_1, FileWriter::APPEND);
  Logger::instance().registerWriter(&file_writer_1);

  FileWriter file_writer_2(Severity::ERROR, file_name_2, FileWriter::BACKUP);
  Logger::instance().registerWriter(&file_writer_2);

  FileWriter file_writer_3(Severity::DEBUG, file_name_3, FileWriter::OVERWRITE);
  Logger::instance().registerWriter(&file_writer_3);

  QDir current_dir = QDir::current();
  QStringList backups =
      current_dir.entryList(QStringList(QString("*_%1").arg(file_name_2)),
                            QDir::Files, QDir::Time | QDir::Reversed);
  QString file_name_4 = backups.first();
  QFile log_file_4(file_name_4);

  Logger::instance() << Severity::INFO << "Message 01" << LogMessage::EOM;
  Logger::instance() << Severity::DEBUG << "Message 02" << LogMessage::EOM;
  Logger::instance() << Severity::ERROR << "Message 03" << LogMessage::EOM;

  QVERIFY(log_file_1.exists());
  QVERIFY(log_file_1.open(QIODevice::ReadOnly | QIODevice::Text));

  QVERIFY(log_file_2.exists());
  QVERIFY(log_file_2.open(QIODevice::ReadOnly | QIODevice::Text));

  QVERIFY(log_file_3.exists());
  QVERIFY(log_file_3.open(QIODevice::ReadOnly | QIODevice::Text));

  QVERIFY(log_file_4.exists());
  QVERIFY(log_file_4.open(QIODevice::ReadOnly | QIODevice::Text));

  QString contents_1 = log_file_1.readAll();
  QVERIFY(!contents_1.isEmpty());
  QVERIFY(contents_1.contains("Old Text 01"));
  QVERIFY(contents_1.contains("Old Text 02"));
  QVERIFY(contents_1.contains("INFO Message 01"));
  QVERIFY(!contents_1.contains("DEBUG Message 02"));
  QVERIFY(contents_1.contains("ERROR Message 03"));

  QString contents_2 = log_file_2.readAll();
  QVERIFY(!contents_2.isEmpty());
  QVERIFY(!contents_2.contains("Old Text 01"));
  QVERIFY(!contents_2.contains("Old Text 02"));
  QVERIFY(!contents_2.contains("INFO Message 01"));
  QVERIFY(!contents_2.contains("DEBUG Message 02"));
  QVERIFY(contents_2.contains("ERROR Message 03"));

  QString contents_3 = log_file_3.readAll();
  QVERIFY(!contents_3.isEmpty());
  QVERIFY(!contents_3.contains("Old Text 01"));
  QVERIFY(!contents_3.contains("Old Text 02"));
  QVERIFY(contents_3.contains("INFO Message 01"));
  QVERIFY(contents_3.contains("DEBUG Message 02"));
  QVERIFY(contents_3.contains("ERROR Message 03"));

  QString contents_4 = log_file_4.readAll();
  QVERIFY(!contents_4.isEmpty());
  QVERIFY(contents_4.contains("Old Text 01"));
  QVERIFY(contents_4.contains("Old Text 02"));
  QVERIFY(!contents_4.contains("INFO Message 01"));
  QVERIFY(!contents_4.contains("DEBUG Message 02"));
  QVERIFY(!contents_4.contains("ERROR Message 03"));

  Logger::destroy();
}

void FrameworkTest::guiLogger()
{
}
