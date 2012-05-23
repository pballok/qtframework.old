#include "testpreferences.h"

TestPreferences* TestPreferences::instance_ = NULL;

TestPreferences& TestPreferences::instance() {
  if (!instance_) {
    instance_ = new TestPreferences();
    atexit(TestPreferences::destroy);
  }

  return *instance_;
}

void TestPreferences::destroy() {
  if (instance_) {
    delete instance_;
    instance_ = NULL;
  }
}

void TestPreferences::readSettings(const QSettings* const settings_file) {
  value_ = settings_file->value(QString::fromAscii("Value"), 0).toUInt();
}

void TestPreferences::writeSettings(QSettings* const settings_file) const {
  settings_file->setValue("Value", value_);
}
