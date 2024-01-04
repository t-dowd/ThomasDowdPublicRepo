TARGET = L2B
SRC_FILES = main.cpp .cpp

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
	
clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp Box.h Box.cpp
box.o: main.cpp Box.h
