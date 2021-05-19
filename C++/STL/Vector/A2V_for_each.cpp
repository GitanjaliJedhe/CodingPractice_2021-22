// Convert array into vector using for_each()

#include <iostream>
#include <vector>
#include <algorithm> // for_each()

using namespace std;

int main()
{
	int arr[] = {9, 18, 27, 36, 45};

	vector<int> vec;

	// Iterate over array elements and add them to vector 
	for_each(begin(arr),
		 end(arr),
		 [&] (const auto &elem) {
		 	vec.push_back(elem);
		 });

	// Print vector
	for(const auto & elem : vec) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 9 , 18 , 27 , 36 , 45 ,
 */
