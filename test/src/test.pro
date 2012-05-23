QT          += core sql
CONFIG      += qtestlib
TARGET       = test
TEMPLATE     = app
INCLUDEPATH += ../..

SOURCES     += ../../consolewriter.cpp \
               ../../filewriter.cpp \
               ../../guiwriter.cpp \
               ../../loggedquery.cpp \
               ../../logger.cpp \
               ../../logmessage.cpp \
               ../../preferences.cpp \
               ../../tracer.cpp \
               main.cpp \
               frameworktest.cpp \
               testpreferences.cpp

HEADERS     += ../../consolewriter.h \
               ../../filewriter.h \
               ../../guiwriter.h \
               ../../loggedquery.h \
               ../../logger.h \
               ../../logmessage.h \
               ../../logwriter.h \
               ../../preferences.h \
               ../../severity.h \
               ../../sevexception.h \
               ../../tracer.h \
               frameworktest.h \
               testpreferences.h



