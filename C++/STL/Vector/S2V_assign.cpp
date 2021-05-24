// Convert set into vector using assign()

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	set<int> set_of_nums {111, 999, 444, 555, 666};

	vector<int> vec_of_nums;

	vec_of_nums.assign(set_of_nums.begin(), set_of_nums.end());

	for(const auto &elem : vec_of_nums)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * 111 , 444 , 555 , 666 , 999 ,
 * */
