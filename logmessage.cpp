#include "logmessage.h"
#include "logger.h"

LogMessage::LogMessage() : severity_(Severity::MIN), message_("") {
  message_stream_.setString(&message_);
}

LogMessage::LogMessage(const Severity::SeverityType severity)
  : severity_(severity), message_("") {
  message_stream_.setString(&message_);
}

LogMessage::LogMessage(const LogMessage& orig_message) {
  severity_ = orig_message.severity_;
  message_ = orig_message.message_;
  message_stream_.setString(&message_);
}

LogMessage::~LogMessage() {
  if (message_ != "") Logger::instance().writeMessage(severity_, message_);
}

LogMessage& LogMessage::operator<<(const LoggerManip manipulator) {
  switch (manipulator) {
    case EOM:   Logger::instance().writeMessage(severity_, message_);
                // There's no 'break' here because the EOM manipulator
                // needs to do a 'CLEAR' as well
    case CLEAR: message_="";
                break;
    default: ;
  }

  return *this;
}
