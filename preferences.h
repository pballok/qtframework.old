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
    file_name_ = QString("%1.ini").arg(app_name);
  }

  inline QString version() const {
    return version_;
  }

  inline void set_version(const QString& version) {
    version_ = version;
  }

  inline QString file_name() const {
    return file_name_;
  }

  void load() throw(SevException);
  void save() const throw(SevException);

 protected:
  Preferences() : app_name_(""), version_(""), file_name_("") {}
  Preferences(Preferences const&) {}
  Preferences& operator=(Preferences const&) {return *this;}
  virtual ~Preferences() {}

  virtual void readSettings(const QSettings* const settings_file) = 0;
  virtual void writeSettings(QSettings* const settings_file) const = 0;

 private:
  QString app_name_;
  QString version_;
  QString file_name_;
};

#endif
