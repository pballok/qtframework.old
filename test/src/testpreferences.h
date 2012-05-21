#ifndef TESTPREFERENCES_H
#define TESTPREFERENCES_H

#include <QString>

#include <preferences.h>

class TestPreferences : public Preferences {
 public:
  static TestPreferences& instance();
  static void destroy();

  inline int value() const throw() {
    return value_;
  }

  inline void set_value(const int value) throw() {
    value_ = value;
  }

 protected:
  TestPreferences() : Preferences(), value_(0) {}
  TestPreferences(TestPreferences const& prefs) : Preferences(prefs) {}
  TestPreferences& operator=(TestPreferences const& prefs) {
    Preferences::operator=(prefs);
    return *this;
  }
  virtual ~TestPreferences() {}

  virtual void readSettings(const QSettings* const settings_file);
  virtual void writeSettings(QSettings* const settings_file) const;

  static TestPreferences* instance_;
  int                     value_;
};

#endif // TESTPREFERENCES_H
