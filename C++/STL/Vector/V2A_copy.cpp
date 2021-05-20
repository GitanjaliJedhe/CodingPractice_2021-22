// Convert vector into an array using STL algorithm copy()

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{	vector<int> vec {7, 14, 21, 28, 35};

	int arr[vec.size()];

	copy(vec.begin(),
	     vec.end(),
	     arr);

	for(const auto &elem : arr) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 7 , 14 , 21 , 28 , 35 ,
 * */
