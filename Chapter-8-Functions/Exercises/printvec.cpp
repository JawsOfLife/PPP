#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//Generate a fibonacci sequency, starting at f[0] = x and f[1] = y, up to n numbers, saving the result in vector v
void fibonacci(int x, int y, vector<int> &v, int n){
	//initialize the result
	v.push_back(x);
	v.push_back(y);

	//push (n-2) elements into the vector
	int count = n-2;
	int index = 2;
	while (count >= 1){
		int next_fib = v[index - 2] + v[index - 1];
		v.push_back(next_fib);
		if (v[index] <= v[index-1]){
			cout << "Overflow Error!\n";
		}
		++index;
		--count;
	}
}

//Print a label and then all of the integers in a vector
void print(string label, vector<int> v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << endl;
	}
}

int main(int argc, char* argv[]){
	/*vector<int> v;
	string inputLabel = "\0";
	int input = 0;
	cout << "Enter some numbers (enter \"s\" to stop) > ";
	while (cin >> input){
		v.push_back(input);
	}
	cout << "What kind of numbers are these? > ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> inputLabel;
	cout << "\n";
	print(inputLabel, v);
	*/

	//Print a fib sequence
	cout << "\nPrinting a fibonacci sequence: \n";
	vector<int> fib;
	fibonacci(1, 1, fib, 20);
	print("Fib", fib);
	return 0;
}