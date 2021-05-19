// Convert an array into a vector in C++ using Range Based Constructor 

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int arr[] = {4, 8, 12, 16, 20, 24};

	vector<int> vec(arr, arr + sizeof(vec) / sizeof(int));

	for(const auto &elem : arr) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;
}

/*OUTPUT:
 * 4 , 8 , 12 , 16 , 20 , 24 ,
 */
