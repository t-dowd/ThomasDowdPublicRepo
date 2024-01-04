TARGET = Linked
SRC_FILES = LinkedListTester.cpp LinkedList.cpp
GTEST_DIR = googletest

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

$(TARGET): $(OBJECTS) gtest
	$(CXX) -o $@ $^ -pthread -lgtest -lgtest_main

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) $(GTEST_DIR)

# DEPENDENCIES
LinkedList.o: LinkedList.cpp Node.hpp LinkedList.h
LinkedListTester.o: Node.hpp LinkedList.cpp LinkedList.h

# Download and build Google Test
gtest:
	git clone https://github.com/google/googletest.git $(GTEST_DIR)
	cd $(GTEST_DIR) && cmake . && make