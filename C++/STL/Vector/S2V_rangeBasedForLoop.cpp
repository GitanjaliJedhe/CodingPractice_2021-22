//Convert set into vector using range based for loop

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	set<string> set_of_names {"Gitanjali", "Snehal", "Rushali"};
	vector<string> vec_of_names;

	for(auto str : set_of_names)
	{
		vec_of_names.push_back(str);
	}

	for(auto str : vec_of_names)
	{
		cout<<str<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * Gitanjali , Rushali , Snehal ,
 * */
