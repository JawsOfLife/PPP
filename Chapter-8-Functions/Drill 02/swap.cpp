#include <iostream>
using namespace std;

//Swap using pass-by-value: only swaps inside the local function
void swap_v(int a, int b){
	int temp; 
	temp = a; 
	a = b;
	b = temp;
}

//Swap using pass-by-reference: swaps the actual values passed into the function
void swap_r(int& a, int& b){
	int temp; 
	temp = a; 
	a = b;
	b = temp;
}

/*
//Fails to compile: can't reassign const variables
void swap_cr(const int& a, const int& b){
	int temp; 
	temp = a; 
	a = b;
	b = temp;
}
*/


int main(int argc, char* argv[]){
	int x = 7;
	int y = 9;
	swap_v(x, y);
	cout << "x == " << x << endl;
	cout << "y == " << y << "\n\n";
	swap_r(x, y);
	cout << "x == " << x << endl;
	cout << "y == " << y << "\n\n";

	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	cout << "cx == " << cx << endl;
	cout << "cy == " << cy << "\n\n";
	//Not allowed: passing a const int to an int& function loses the "const" modifier and won't compile
	/*
	swap_r(cx, cy);
	cout << "cx == " << cx << endl;
	cout << "cy == " << cy << "\n\n";
	*/

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	cout << "dx == " << dx << endl;
	cout << "dy == " << dy << "\n\n";

	//Not allowed: can't pass a double into int& function
	/*
	swap_r(dx, dy);
	cout << "dx == " << dx << endl;
	cout << "dy == " << dy << "\n\n";
	*/
	swap_r( (int)dx, (int)dy);



	return 0;
}