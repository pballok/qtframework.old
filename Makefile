CXX           = g++
CXXFLAGS      = -Wall
INCPATH       =
LINK          = g++
LFLAGS        =
LIBS          =

SOURCES       = logger.cpp \
		consolewriter.cpp \
		test.cpp

OBJECTS       = logger.o \
		consolewriter.o \
		test.o

TARGET        = test

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

logger.o: logger.cpp logger.h logwriter.h severity.h
	$(CXX) -c $(CXXFLAGS) $(INcPATH) -o logger.o logger.cpp

consolewriter.o: consolewriter.cpp consolewriter.h logwriter.h
	$(CXX) -c $(CXXFLAGS) $(INcPATH) -o consolewriter.o consolewriter.cpp

test.o: test.cpp logger.h consolewriter.h logwriter.h severity.h
	$(CXX) -c $(CXXFLAGS) $(INcPATH) -o test.o test.cpp

