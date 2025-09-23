PROJECT = bmp_processor
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
LGTESTFLAGS = -lgtest -lgtest_main -pthread

DEPS = $(wildcard *.hpp)

OBJ = bmp_processor.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) -o $@ main.o $(OBJ)

all: $(PROJECT)


.PHONY: clean

clean:
	rm -f $(PROJECT) bmp_processor.o main.o 1.bmp 2.bmp 3.bmp
