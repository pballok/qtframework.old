#include <QFile>

#include "preferences.h"

void Preferences::load() {
  bool file_exists = QFile::exists(settings_file_name_);

  QSettings pref_file(settings_file_name_, QSettings::IniFormat);

  readSettings(&pref_file);

  if (!file_exists) {
    save(); // If INI file did not exist before, save default settings
  }
}

void Preferences::save() const {
  QSettings pref_file(settings_file_name_, QSettings::IniFormat);

  writeSettings(&pref_file);
}
