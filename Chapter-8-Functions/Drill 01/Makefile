print: my.o use.o
	g++ -std=c++11 -g -o print my.o use.o

my.o: my.cpp my.h
	g++ -std=c++11 -g -c my.cpp

use.o: use.cpp my.h
	g++ -std=c++11 -g -c use.cpp

clean:
	rm -f print my.o use.o
