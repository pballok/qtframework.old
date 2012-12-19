#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QString>
#include <QSettings>

#include <sevexception.h>

class Preferences {
 public:
  inline QString app_name() const {
    return app_name_;
  }

  inline void set_app_name(const QString& app_name) {
    app_name_ = app_name;
    settings_file_name_ = QString("%1.ini").arg(app_name);
  }

  inline QString app_version() const {
    return app_version_;
  }

  inline void set_app_version(const QString& version) {
    app_version_ = version;
  }

  inline QString framework_version() const {
    return framework_version_;
  }

  inline QString settings_file_name() const {
    return settings_file_name_;
  }

  void load();
  void save() const;

 protected:
  Preferences() : app_name_(""), app_version_(""), framework_version_("1.0"), settings_file_name_("") {}
  Preferences(Preferences const&) {}
  Preferences& operator=(Preferences const&) {return *this;}
  virtual ~Preferences() {}

  virtual void readSettings(QSettings* const settings_file) = 0;
  virtual void writeSettings(QSettings* const settings_file) const = 0;

 private:
  QString app_name_;
  QString app_version_;
  QString framework_version_;
  QString settings_file_name_;
};

#endif
