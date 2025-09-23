PROJECT = bmp_processor
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -fopenmp
LGTESTFLAGS = -lgtest -lgtest_main -pthread

DEPS = $(wildcard *.hpp)

OBJ = bmp_processor.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ main.o $(OBJ) -fopenmp  

all: $(PROJECT)

TEST_OBJ = tests.o
TEST_PROJECT = tests

$(TEST_PROJECT): $(TEST_OBJ) $(OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(OBJ) $(LGTESTFLAGS) -fopenmp

.PHONY: clean test

clean:
	rm -f $(PROJECT) $(TEST_PROJECT) bmp_processor.o main.o 1.bmp 2.bmp 3.bmp

test: $(TEST_PROJECT)
	./$(TEST_PROJECT)
