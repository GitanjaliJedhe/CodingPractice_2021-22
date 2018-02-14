CC=g++
CCFLAGS=-c -g -I include/
LDFLAGS=
INCPATH=./include
OBJPATH=./bin
SOURCES=stack.cpp test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJPATH)/$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/$@

.cpp.o:	
	$(CC) $(CCFLAGS) src/$< -o bin/$@

clean:
	rm -f src/$(EXECUTABLE) bin/*.o
