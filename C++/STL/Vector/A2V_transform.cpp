// Convert array into vector and transform elements on the way 

#include <iostream>
#include <vector>
#include <algorithm> // back_inserter() and transform()

using namespace std;

int main()
{
	int arr[] = {2, 4, 6, 8, 10};

	vector<int> vec;

	transform(begin(arr),
			end(arr),
			back_inserter(vec),
			[] (const auto &elem)
			{
				return elem * 2;
			});

	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 4 , 8 , 12 , 16 , 20 ,
 * */
