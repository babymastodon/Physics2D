
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
			Graphics.o\
			EventHandler.o\
			Thread.o\
			PObject.o\
			PElipse.o\
			PMovingObject.o\
			WorldTreeNode.o\
			PRectangle.o\
			PEquilateralTriangle.o

all: Makefile $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $*.o $(VPATH)/$*.cpp 
