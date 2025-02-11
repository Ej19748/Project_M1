# Makefile for Student Grades Program

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

# Default target
all: $(TARGET)

# Link objects to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile sources into objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)