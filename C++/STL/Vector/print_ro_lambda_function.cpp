// Print vector in reverse order using lambda function

#include <iostream>  // cout
#include <vector>    // vector
#include <algorithm> // for_each

using namespace std;

int main()
{
	vector<char> vec {'G', 'i', 't', 'a', 'n', 'a', 'l', 'i'};

	for_each(vec.rbegin(),
		 vec.rend(),
		 [] (const auto &elem) {
		 	cout<<elem<<" , ";
		});

	return 0;
}

/*Output:
 * i , l , a , n , a , t , i , G ,
 * */
