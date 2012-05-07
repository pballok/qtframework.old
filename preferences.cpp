#include "preferences.h"

Preferences* Preferences::instance_ = NULL;

Preferences::Preferences(const QString &app_name, const QString &version)
    : app_name_(app_name), version_(version) {
  file_name_ = QString("./%1.ini").arg(app_name_);
}

void Preferences::load() throw(SevException)
{
  QSettings pref_file(file_name_, QSettings::IniFormat);
  if (pref_file.status() != QSettings::NoError) {
    throw SevException(Severity::WARNING,
                QString("Failed to open preferences file: %1").arg(file_name_));
  }

  readSettings(&pref_file);
}

void Preferences::save() const throw(SevException)
{
  QSettings pref_file(file_name_, QSettings::IniFormat);
  if (pref_file.status() != QSettings::NoError) {
    throw SevException(Severity::WARNING,
            QString("Failed to write to preferences file: %1").arg(file_name_));
  }

  writeSettings(&pref_file);
}

