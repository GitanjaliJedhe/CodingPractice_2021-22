// Convert vector into set using copy

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	vector<int> vec_of_nums {2008, 2010, 2013, 2016, 2021};

	set<int> set_of_nums;

	copy(vec_of_nums.begin(),
	     vec_of_nums.end(),
	     inserter(set_of_nums, set_of_nums.begin())
	     );

	
	for(const auto &elem : set_of_nums)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 2008 , 2010 , 2013 , 2016 , 2021 ,
 * */
