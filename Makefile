
CXX = g++
CXXFLAGS = -Wall
DEL_FILE = rm -f
LINK = g++
LIBS =  -lSDL -lGLU -lGL
TARGET = Physics2D
VPATH = ./src

OBJECTS =	main.o\
			Physics.o\
			SceneGraph.o\
			Graphics.o

all: Makefile $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $*.o $(VPATH)/$*.cpp 
