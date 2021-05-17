#include <iostream>
#include <algorithm>

using namespace std;

void display(int a)
{	
	cout<<a<<" , ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	for_each(arr, arr + (sizeof(arr) / sizeof(int)), display); // without Lambda Function

	cout<<endl;
	
	int mul = 5;

	for_each(arr, 
		arr + (sizeof(arr) / sizeof(int)), 
		[](auto &elem) {
		cout<<elem<<" , ";
		//cout<<mul<<endl; outer scope elements are not visible
		} // Lambda Function
		);
	
	cout<<endl;

	//using [=] pass by value
	for_each(arr, 
		arr + (sizeof(arr) / sizeof(int)), 
		[=](auto &elem) {
		elem = elem * mul;
		//mul = 9; read-only access
		} // Lambda Function
		);
	
	cout<<endl;

	//using [&] pass by reference
	for_each(arr, 
		arr + (sizeof(arr) / sizeof(int)), 
		[&](auto &elem) {
		mul = 3; // write access
		cout<<"mul = "<<mul<<endl;
		} // Lambda Function
		);
	
	exit(0);
}
