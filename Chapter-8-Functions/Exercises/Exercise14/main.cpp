#include <iostream>
using namespace std;

/*
Foo takes an argument of a constant integer x, and returns nothing. One reason for writing a function like this might be to write a pure statement with no side effects; the function doesn't change any inputs, and returns nothing back. It is not done often because the functionality of a function written this way is very limited, as we usually want side effects from functions.
*/
void foo(const int x){
	cout << "The value of x is " << x << ".\n";
}

int main(int argc, char** argv){
	int x = 5;
	foo(x);
	return 0;
}