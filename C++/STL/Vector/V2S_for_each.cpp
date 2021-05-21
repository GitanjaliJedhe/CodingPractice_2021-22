// Convert vector into set using for_each()

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> vec_of_string {"Gitanjali", "Dilip", "Jedhe"};
	
	set<string> set_of_string;

	for_each(vec_of_string.begin(),
		vec_of_string.end(),
		[&] (auto &elem) {
			set_of_string.insert(elem);
		});

	for(const auto &elem : vec_of_string)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * Gitanjali , Dilip , Jedhe ,
 * */
