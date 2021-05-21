// Convert vector into set using transform()

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	vector<char> vec_of_char {'J', 'e', 'd', 'h', 'e'};

	set<char> set_of_char;

	transform(vec_of_char.begin(),
		  vec_of_char.end(),
		  inserter(set_of_char, set_of_char.begin()),
		  [] (const auto &elem)
		  {
		  	return elem;
		  });

	for(const auto &elem : set_of_char) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;


	return 0;
}

/*Output:
 * J , d , e , h ,
 * */
