// Convert vector into set using Range Based Constructor

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	vector<char> letters {'G', 'i', 't', 'a', 'j', 'a', 'l', 'i'};

	set<char> set_of_letters(letters.begin(), letters.end());

	for(const auto &elem :  letters)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	return 0;
}

/*Output:
 * G , i , t , a , j , a , l , i ,
 * */
