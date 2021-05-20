// Convert a vector into an array by copying items one by one

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = {99, 11, 55, 33};

	int arr[vec.size()];

	for(int i = 0; i < vec.size(); i++)
	{
		arr[i] = vec[i];
	}

	for(const auto &elem : arr)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 99 , 11 , 55 , 33 ,
 * */
