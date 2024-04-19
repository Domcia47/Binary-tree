CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

# Lista plików źródłowych i docelowych
SOURCES := BinaryTree.cpp
EXECUTABLES := BinaryTree.x

# Pliki obiektowe
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean make

all: $(EXECUTABLES)

BinaryTree.x: BinaryTree.o BinaryTree.hpp

%.o: %.cpp BinaryTree.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

make: $(OBJECTS) $(EXECUTABLES)

clean:
	$(RM) $(EXECUTABLES) $(OBJECTS)

