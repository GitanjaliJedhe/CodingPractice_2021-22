// Convert set into vector using copy()

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	set<int> set_of_nums = {2020, 2021, 2022, 2050};
	
	vector<int> vec_of_nums;

	copy(begin(set_of_nums),
	     end(set_of_nums),
	     inserter(vec_of_nums, vec_of_nums.begin()));

	for(const auto &elem : vec_of_nums)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 2020 , 2021 , 2022 , 2050 ,
 * */
