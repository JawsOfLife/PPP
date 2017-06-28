#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

//Print a label and then all of the integers in a vector
void print(string label, vector<string> &v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << " ";
	}
	cout << "\n";
}

void print(string label, vector<double> &v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]){
	vector<string> names;
	vector<double> ages;
	string input_name = "\0";
	double input_age = 0.0;
	int count = 5;

	cout << "Enter 5 names > ";
	while (count >= 1){
		cin >> input_name;
		names.push_back(input_name);
		--count;
	}
	cout << "\n";
	cout << "Enter 5 ages > ";
	count = 5;
	while (count >= 1){
		cin >> input_age;
		ages.push_back(input_age);
		--count;
	}

	cout << endl;
	print("Names", names);
	print("Ages", ages);
	cout << endl;

	//Sort the names
	vector<string> s_temp = names;
	sort(names.begin(), names.end());
	print("Sorted Names", names);

	//Sort the ages to correspond to the names
	vector<double> sortedAges;
	int i = 0;
	int j = 0;
	int sortCount = 0;
	while(sortCount < names.size()){
		//Find the position of the first sorted element in the old vector
		while (s_temp[i] != names[j]){
			++i;
		}
		//The age of the name at position i is the corresponding age of the sorted element
		sortedAges.push_back(ages[i]);
		i = 0;
		++sortCount;
		j = sortCount; //move on to the next element of the sorted array
	}
	
	print("Sorted Ages", sortedAges);
	//sortedAges.push_back(ages[i]);
	//print(sortedAges);

	cout << endl;

	return 0;
}