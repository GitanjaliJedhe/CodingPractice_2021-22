#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator <<(ostream &os, vector<T> &vec) {
	for(auto elem : vec) {
		os<<elem<<" , ";
	}
	return os;
}

template <typename T>
void print_vector(vector<T> &vec, string sp = "") {
	for(auto elem : vec) {
		cout<<elem<<sp;
	}
	cout<<endl;
}

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

	return 0;
}
