// Convert vector into an array using vector::data()

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec {22, 44, 66, 88};
	
	int *refArr = vec.data();

	int size = vec.size();
	for(int i = 0; i < size; i++)
	{
		refArr[i] = refArr[i] - 11;
		cout<<refArr[i]<<" , ";
	}
	cout<<endl;


	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 11 , 33 , 55 , 77 ,
 * 11 , 33 , 55 , 77 ,
 * */
