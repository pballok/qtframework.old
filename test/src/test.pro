QT          += core
CONFIG      += qtestlib
TARGET       = test
TEMPLATE     = app
INCLUDEPATH += ../..

SOURCES     += ../../filewriter.cpp \
               ../../logger.cpp \
               ../../logmessage.cpp \
               ../../preferences.cpp \
               main.cpp \
               frameworktest.cpp

HEADERS     += ../../filewriter.h \
               ../../logger.h \
               ../../logmessage.h \
               ../../logwriter.h \
               ../../preferences.h \
               ../../severity.h \
               ../../sevexception.h \
               frameworktest.h

