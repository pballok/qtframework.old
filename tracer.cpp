#include "severity.h"
#include "tracer.h"
#include "logger.h"

unsigned int Tracer::indent_ = 0;

Tracer::Tracer(const QString& func_name, const QString& params)
    : func_name_(func_name) {
  QString message( indent_++, ' ');
  message += func_name;
  message += "(";
  message += params;
  message += ") >";

  Logger::instance().writeMessage(Severity::DEBUG, message);
}

Tracer::~Tracer() {
  QString message(--indent_, ' ');
  message += func_name_;
  message += "(";
  message += param_stream_.string();
  message += ") <";

  Logger::instance().writeMessage(Severity::DEBUG, message);
}
