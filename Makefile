CXX = g++
CXXFLAGS = -Wall -Wpedantic -O2

all: bmp_processor create_test_bmp

bmp_processor: main.o bmp_processor.o
	$(CXX) $(CXXFLAGS) -o bmp_processor main.o bmp_processor.o

create_test_bmp: create_test_bmp.o bmp_processor.o
	$(CXX) $(CXXFLAGS) -o create_test_bmp create_test_bmp.o bmp_processor.o

main.o: main.cpp bmp_processor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bmp_processor.o: bmp_processor.cpp bmp_processor.h
	$(CXX) $(CXXFLAGS) -c bmp_processor.cpp

create_test_bmp.o: create_test_bmp.cpp bmp_processor.h
	$(CXX) $(CXXFLAGS) -c create_test_bmp.cpp

clean:
	rm -f *.o bmp_processor create_test_bmp rotated_clockwise.bmp rotated_counterclockwise.bmp blurred_image.bmp input.bmp
