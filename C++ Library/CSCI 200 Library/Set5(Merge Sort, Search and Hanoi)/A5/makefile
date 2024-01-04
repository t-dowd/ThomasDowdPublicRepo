# A line starting with a has is a comment, we'll build up
# the below example

TARGET = A5
SRC_FILES = main.cpp MazeFunctions.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
LinkedListFunctions.o: MazeFunctions.cpp MazeFunctions.h MazeNode.h
main.o: main.cpp MazeNode.h MazeFunctions.cpp 