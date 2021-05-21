// Print vector in reverse order using copy()

#include <iostream>  // cout
#include <vector>    // vector 
#include <iterator>  // ostream_iterator
#include <algorithm> // copy

using namespace std;

int main()
{
	vector<int> vec {786, 989, 484, 787};

	ostream_iterator<int> out_int(cout, " , ");
	copy(vec.rbegin(),
	     vec.rend(),
	     out_int
	    );

	cout<<endl;
}

/*Output:
 * 787 , 484 , 989 , 786 ,
 * */
