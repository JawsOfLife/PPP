#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Result to return from stats()
struct result {
	int min;
	int max;
	double avg;
	double median;
} ;

//Print a label and then all of the integers in a vector
void print(string label, vector<int> &v){
	int count = 1;
	cout << label << ":" << endl;
	for (auto i : v){
		//Print a newline to format output
		if (count % 20 == 0){
			cout << endl;
		}
		cout << i << " ";
		++count;
	}
	cout << "\n";
}

template <typename T>
void print(string label, vector<T> &v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << " ";
	}
	cout << "\n";
}

//stats returns the minimum and maximum values in an integer vector, as well as the mean and median of the vector, all in a result struct
result stats(vector<int> &v){
	result r;
	int middleIndex = v.size() / 2;
	double sum = 0;
	r.min = numeric_limits<int>::max();
	r.max = numeric_limits<int>::min();
	r.avg = 0;
	r.median = 0;

	//Find the minimum and maxium element
	for (auto i : v){
		if ( i < r.min){
			r.min = i;
		}
		if (i > r.max){
			r.max = i;
		}
		sum += i;
	}
	//Calculate the average
	r.avg = sum / v.size();

	//Calculate the median
	sort(v.begin(), v.end());
	//If the vector has an even number of elements, return the avg. of the two middle elements
	if (v.size() % 2 == 0){
		double middle_left = v[middleIndex - 1];
		double middle_right = v[middleIndex];
		r.median = (middle_left + middle_right) / 2;
	}
	//Otherwise, return the middle element
	else{
		r.median = v[middleIndex];
	}



	return r;

}


int main(int argc, char* argv[]){
	vector<int> v;
	int vecSize = 1;
	result r;
	srand(time(NULL));
	cout << "Enter the size of the random vector to be generated > ";
	cin >> vecSize;

	//Generate random numbers based on user input
	for (int i = 0; i < vecSize; i++){
		v.push_back(rand() % 100 + 1);
	}
	print("Original Data", v);
	r = stats(v);
	print("Sorted Data", v);
	cout << "The max is " << r.max << "\n";
	cout << "The min is " << r.min << "\n";
	cout << "The average is " << r.avg << "\n";
	cout << "The median is " << r.median << "\n";

	return 0;
}