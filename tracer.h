#ifndef TRACER_H
#define TRACER_H

#include <QString>
#include <QTextStream>

class Tracer {
public:
  static unsigned int indent_;

  Tracer(const QString& func_name, const QString& params = "");
  ~Tracer();

  template<typename T>
  Tracer& operator<<(const T param) {
    param_stream_ << param;
    return *this;
  }

private:
  QString func_name_;
  QString out_param_;
  QTextStream param_stream_;
};

#endif
