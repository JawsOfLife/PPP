#include <iostream>
#include <string>
using namespace std;

namespace X{
	string name = "X";
	int var = 0;
	int print(){
		cout << name << "'s var == " << var << endl;
	}
}

namespace Y{
	string name = "Y";
	int var = 0;
	int print(){
		cout << name << "'s var == " << var << endl;
	}
}

namespace Z{
	string name = "Z";
	int var = 0;
	int print(){
		cout << name << "'s var == " << var << endl;
	}
}


int main(int argc, char* argv[]){
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print(); //should print 9
	{
		using Z::var; 
		using Z::print;
		var = 11; //set Z's var
		print();
	}

	return 0;
}