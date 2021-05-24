// Convert Set into vector using Range Based Constructor

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	set<int> set_of_nums {1, 5, 10, 15, 20};

	vector<int> vec(set_of_nums.begin(), set_of_nums.end());

	for(const auto &elem : vec)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 1 , 5 , 10 , 15 , 20 ,
 * */
