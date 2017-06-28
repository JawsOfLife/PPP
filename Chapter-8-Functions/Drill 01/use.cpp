#include "my.h"
#include <iostream>
int foo;
using namespace std;

int main(int argc, char* argv[]){
	int i = 0;
	foo = 7;
	print_foo();
	cout << "Enter a number to print < ";
	cin >> i;
	print(i);
}