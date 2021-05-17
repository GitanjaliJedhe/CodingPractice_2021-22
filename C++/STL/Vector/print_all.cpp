#include <iostream>
#include <vector>
#include <iterator>
#include <experimental/iterator>
#include <algorithm> //for_each

using namespace std;

// Overloading << operator
template <typename T>
ostream& operator <<(ostream &os, vector<T> &vec) {
	for(auto elem : vec) {
		os<<elem<<" , ";
	}
	return os;
}

// Custom separator
template <typename T>
void print_vector(vector<T> &vec, string sp = "") {
	for(auto elem : vec) {
		cout<<elem<<sp;
	}
	cout<<endl;
}

// Using Indexing
template <typename T>
void display_vector(vector<T> &vec, string sp = "") {
	for(int i = 0; i < vec.size(); i++) {
		cout<<vec[i]<<sp;
	}
	cout<<endl;
}

int main() {
	vector<int> vecOfInt {1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout<<vecOfInt<<endl;

	print_vector(vecOfInt, ",");

	vector<string> vecOfString {"Gitanjali", "Dilip", "Jedhe"};

	print_vector(vecOfString, "|");

	display_vector(vecOfString, ",");

	// std::copy
	copy(vecOfInt.begin(), 
	     vecOfInt.end(),
	     ostream_iterator<int>(std::cout, " "));

	cout<<endl;

	//C++17 experimental::make_ostream_joiner
	copy(vecOfInt.begin(), 
	     vecOfInt.end(),
	     experimental::make_ostream_joiner(std::cout, "  "));

	cout<<endl;

	// Lambda Function
	for_each(vecOfInt.begin(), 
	         vecOfInt.end(),
	         [](const auto &elem) {
	    		cout<<elem<<", ";
	    	});

	return 0;
}
