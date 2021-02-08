all: openhttest unorderedhttest

unorderedhttest: unorderedhttest.cpp
	g++ -std=c++11 -o  unorderedhttest unorderedhttest.cpp unorderedht.cpp unorderedht.h

openhttest: openhttest.cpp
	g++ -std=c++11 -o  openhttest openhttest.cpp openht.cpp openht.h



# List all the executables under 'all:'
clean:
	rm *.o openhttest unorderedhttest