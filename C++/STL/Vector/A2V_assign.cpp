// Create an empty vector and fill with items from vector 

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[] = {0, 1, 0, 1, 0, 1};

	vector<int> vec;

	vec.assign(begin(arr), end(arr));

	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 0 , 1 , 0 , 1 , 0 , 1 ,
 */
