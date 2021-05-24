// Convert set into vector using transform()

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	set<string> set_of_nums {"Gitanjali", "Dilip", "Jedhe"};
	
	vector<string> vec_of_nums;

	transform(set_of_nums.begin(),
		  set_of_nums.end(),
		  inserter(vec_of_nums, vec_of_nums.begin()),	
		 [] (auto &elem)
		 {
			return elem;
		 });

	for(const auto &elem : vec_of_nums)
	{
		cout<<elem<<" , ";
	}

	cout<<endl;

	return 0;
}

/*Output:
 *Dilip , Gitanjali , Jedhe ,
 */
