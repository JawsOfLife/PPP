#include <iostream>
#include "my.h"

//Prints the value of "foo", declared in my.h
void print_foo(){
	std::cout << "Print_foo: " << foo << "\n";
}

void print(int i){
	std::cout << "Print: " << i << "\n";
}