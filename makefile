CC=g++
CFLAGS=-c -Wall
LDFLAGS=-larmadillo -lboost_regex
SOURCES=calc.hpp calc.cpp rules.hpp rules.cpp function.hpp function.cpp interpreter.hpp function_objects.hpp function_objects.cpp interpreter.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BjaanesCalc

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ -O1

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o

superduperclean:
	rm $(EXECUTABLE)
