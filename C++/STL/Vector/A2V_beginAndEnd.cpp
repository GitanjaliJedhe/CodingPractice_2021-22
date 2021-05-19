// Convert array into vector in C++ - begin() / end()

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[] = {3, 6, 9, 12, 15};

        // Create a vector from array 	
	vector<int> vec(begin(arr), end(arr));

	// Print all elements of vector on console
	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*
 * Output:
 * 3 , 6 , 9 , 12 , 15 ,
 * */
