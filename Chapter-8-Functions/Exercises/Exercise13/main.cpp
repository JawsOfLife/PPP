#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

/*
Prompt: Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string. Also find the longest and shortest string and the lexicopgraphically first and last string. How many separate functions woudl you use for the tasks? Why? 
*/

//findLexiFirst() finds the lexicographically first string in a vector of strings
void findLexiFirst(vector<string> source, vector<string> &s, string &first){
	int min = numeric_limits<int>::max();
	int firstIndex = 0;
	int count = 0;

	//Find the lexi first string
	for (auto i : s){
		if (i[0] < min){
			min = i[0];
			firstIndex = count;
		}
		//tie for min: check all subsequent letters, making sure the index is in bounds for both words being compared
		else if (i[0] == min){
			for (int k = 1; (k < i.length() && k < s[firstIndex].length() ); k++){
				if(i[k] < s[firstIndex][k]){
					min = i[k];
					firstIndex = count;
					break;
				}
				//If the last letter of the new string is the same and the new string is shorter than the previous min, make the new string the new min
				if ( (k+1) == i.length() && i[k] == s[firstIndex][k]){
					min = i[k];
					firstIndex = count;
					break;
				}
			}
		}
	++count;
	}
	first = source[firstIndex];
}

//findLexiLast() finds the lexicographically last string in a vector of strings
void findLexiLast(vector<string> source, vector<string> &s, string &last){
	int max = numeric_limits<int>::min();
	int lastIndex = 0;
	int count = 0;

	for (auto i: s){
		if (i[0] > max){
			max = i[0];
			lastIndex = count;
		}
		//tie for max
		else if (i[0] == max){
			for (int k = 1; (k < i.length() && k < s[lastIndex].length() ); k++){
				if (i[k] > s[lastIndex][k]){
					max = i[k];
					lastIndex = count;
					break;
				}
				//In the case of the maximum lexi string, if the current letter of the current string is the same as the last letter of the last string, and if the current string is longer, make it the new lexi max string
				if ( (k+1) == s[lastIndex].length() && i[k] == s[lastIndex][k]){
					cout << "s[lastIndex].lenght() == " << s[lastIndex].length() << endl;
					max = i[k];
					lastIndex = count;
					break;
				}
			}
		}
	++count;
	}

	last = source[lastIndex];
}

//toLower make all characters of a string lowercase
string toLower(string &s){
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}


void alphaSort(vector<string> &s, string &first, string &last){
	vector<string> lower;
	//convert all strings to lowercase
	for (auto i : s){
		lower.push_back(toLower(i));
	}
	findLexiFirst(s, lower, first);
	findLexiLast(s, lower, last);
}

//charCount takes in a vector of strings s and returns a vector of integers corresponding to the length of the strings in s.
vector<int> charCount(vector<string> &s){
	vector<int> retVec;
	int index = 0; //index for putting string lengths into retVec
	for (auto i : s){
		retVec.push_back(i.length());
		++index;
	}
	return retVec;
}

void findShortestAndLongest(vector<string> &s, string &shortest, string &longest){
	int max = numeric_limits<int>::min();
	int maxIndex = -1;
	int min = numeric_limits<int>::max();
	int minIndex = -1;
	int count = 0;
	vector<int> temp;
	temp = charCount(s);
	//Find the longest and shortest strings
	for (auto i: temp){
		if (i > max){
			max = i;
			maxIndex = count;
		}
		if (i < min){
			min = i;
			minIndex = count;
		}
		++count;
	}
	shortest = s[minIndex];
	longest = s[maxIndex];
}

//print() prints the contents of a vector along with a label
template <typename T>
void print(string label, vector<T> &v){
	cout << label << ":" << endl;
	for (auto i : v){
		cout << i << " ";
	}
	cout << "\n\n";
}




int main(int argc, char** argv){
	vector<string> cities {"Davis", "Dansberg", "Chico", "Chester", "Chakanukawalatamora", "Cha", "Sacramento", "Woodland", "Wozden", "Wozdenstein", "Weed"};
	string longest{};
	string shortest{};
	string first{};
	string last{};
	//Find shortest and longest strings;
	findShortestAndLongest(cities, shortest, longest);
	//Find lexi first and last strings
	alphaSort(cities, first, last);
	print("Cities", cities);
	cout << "The shortest string is " << shortest << ".\n";
	cout << "The longest string is " << longest << ".\n";
	cout << "The lexicographically first string is " << first << ".\n";
	cout << "The lexicographically last string is " << last << ".\n";
	return 0;
}