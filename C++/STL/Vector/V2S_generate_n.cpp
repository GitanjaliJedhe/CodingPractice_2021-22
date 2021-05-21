// Covert vector into set using generate_n()

#include <iostream>
#include <vector>
#include <set>
#include <algorithm> //generate_n()

using namespace std;

int main()
{
	vector<char> vec_of_chars {'G', 'i', 't', 'a', 'n', 'j', 'a', 'l', 'i'};

	set<char> set_of_chars;

	int i = 0;
	generate_n(inserter(set_of_chars, set_of_chars.begin()), //first
		   vec_of_chars.size(),                          // count
		   [&] () {                                      // callback
		   	return vec_of_chars[i++];
		   });

	for(const auto &elem : set_of_chars) 
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * G , a , i , j , l , n , t ,
 * */
