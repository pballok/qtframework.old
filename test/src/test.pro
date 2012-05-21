QT          += core
CONFIG      += qtestlib
TARGET       = test
TEMPLATE     = app
INCLUDEPATH += ../..

SOURCES     += ../../consolewriter.cpp \
               ../../filewriter.cpp \
               ../../guiwriter.cpp \
               ../../logger.cpp \
               ../../logmessage.cpp \
               ../../preferences.cpp \
               main.cpp \
               frameworktest.cpp \
               testpreferences.cpp

HEADERS     += ../../consolewriter.h \
               ../../filewriter.h \
               ../../guiwriter.h \
               ../../logger.h \
               ../../logmessage.h \
               ../../logwriter.h \
               ../../preferences.h \
               ../../severity.h \
               ../../sevexception.h \
               frameworktest.h \
               testpreferences.h



