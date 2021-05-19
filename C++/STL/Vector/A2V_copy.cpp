// Convert an array into vector using copy() algorithm

#include <iostream>    //std::cout
#include <vector>     //std::vector
#include <algorithm> //std::copy
#include <iterator> //std::back_inserter

using namespace std;

int main()
{
	int arr[] = {11, 22, 33, 44, 55};

	vector<int> vec;
	/*
	 * back_inserter : allow algorithms that usually overwrite elements (such as copy)
	 * to instead insert new elements automatically at the end of the container*/

	copy(begin(arr),
	     end(arr),
	     back_inserter(vec)); 

	// Print vector
	for(const auto &elem : vec) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 11 , 22 , 33 , 44 , 55 ,
 * */
