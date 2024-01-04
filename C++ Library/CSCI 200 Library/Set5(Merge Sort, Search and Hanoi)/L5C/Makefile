# A line starting with a has is a comment, we'll build up
# the below example

TARGET = L5C
SRC_FILES = main.cpp LinkedListFunctions.cpp

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
LinkedListFunctions.o: LinkedListFunctions.cpp LinkedListFunctions.h Node.h
main.o: main.cpp Node.h LinkedListFunctions.cpp 