TARGET = A1
SRC_FILES = main.cpp

CXX = g++
CFLAG = -Wall -g
OBJECTS = $(SRC_FILES:.cpp=.o)
	ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ -c $<
	$(CXX) $(CFLAGS) -o $@ -c $<
clean:
	$(DEL) $(TARGET) $(OBJECTS)