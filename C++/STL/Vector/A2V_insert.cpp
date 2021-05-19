// Create an empty vector in C++ and add array elements to it

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	vector<int> vec;

	// Add array elements to vector
	vec.insert(vec.begin(), begin(arr), end(arr));

	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}

	cout<<endl;

	return 0;
}
/*Output:
 * 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 ,
 * */
