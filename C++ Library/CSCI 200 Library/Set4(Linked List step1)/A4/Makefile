TARGET = A4
SRC_FILES = main.cpp LeftRightCenterFunctions.cpp

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

LeftRightCenterFunctions.o: LeftRightCenterFunctions.h LeftRightCenterFunctions.cpp Node.h
main.o: main.cpp Node.h LeftRightCenterFunctions.cpp