#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QString>
#include <QSettings>

#include <sevexception.h>

class Preferences
{
 public:
  static Preferences* instance();

  inline QString app_name() const {
    return app_name_;
  }

  inline QString version() const {
    return version_;
  }

  void load() throw(SevException);
  void save() const throw(SevException);

 protected:
  Preferences(const QString &app_name, const QString &version);

  virtual ~Preferences() {}

  virtual void   readSettings(QSettings *settings_file) = 0;
  virtual void   writeSettings(QSettings *settings_file) const = 0;

  static Preferences* instance_;

 private:
  QString app_name_;
  QString version_;
  QString file_name_;
};

#endif
