// Print vector in reverse order using reverse iterator

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void reverse_print(vector<T> &vec, string sep = " ")
{
	for(auto it = vec.rbegin(); it != vec.rend(); it++) 
	{
		cout<<*it<<sep;
	}
	cout<<endl;
}

int main() 
{
	vector<int> vec {1, 2, 3, 4, 5, 6};

	reverse_print(vec, " , ");

	return 0;
}

/*Output:
 * 6 , 5 , 4 , 3 , 2 , 1 ,
 * */
