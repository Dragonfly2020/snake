CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
SOURCES=main.cpp game.cpp snake.cpp fruit.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=snake

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -fr $(EXECUTABLE) $(OBJECTS)

