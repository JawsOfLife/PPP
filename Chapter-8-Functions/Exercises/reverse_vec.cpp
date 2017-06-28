#include <iostream>
#include <vector>
#include <limits>
using namespace std;


//Return a reversed vector, leaving the original vector unchanged
vector<int> newReverse(vector<int> &v){
	vector<int> rev; //reversed vector to return
	//iterate backwards through the source vector
	for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++){
		rev.push_back(*rit);
	}
	return rev;
}

//changeReverse modifies an input vector by reversing it
void changeReverse(vector<int> &v){
	newReverse(v).swap(v);
}

//Print a label and then all of the integers in a vector
void print(string label, vector<int> v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << " ";
	}
}

int main(int argc, char* argv[]){
	vector<int> v {1,2,3,4,5};
	print("Original Vector", v);
	cout << "\n\n";

	//Make a new vector that is the reverse of v
	vector<int> v_rev;
	v_rev = newReverse(v);
	print("New Reversed Vector", v_rev);
	cout << "\n\n";

	//Reverse the original vector
	changeReverse(v);
	print("Original Vector Reversed", v);

	cout << endl;

	return 0;
}