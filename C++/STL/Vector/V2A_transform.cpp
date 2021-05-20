// Convert vector into an array using STL algorithm transform()

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec {98, 2, 97, 3, 96, 4};

	int arr[vec.size()];

	transform(vec.begin(), 
		  vec.end(),               //Input range
		  arr,                     // Output Iterator
		  [] (const auto &elem) { // Unary function
		  	return elem;
		  });

	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 98 , 2 , 97 , 3 , 96 , 4 ,
 * */
