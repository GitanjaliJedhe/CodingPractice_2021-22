// Iterate map in reverse order

#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

int main()
{
	map<string, int> mapOfStudentCount;

	mapOfStudentCount.insert(pair<string, int> ("Div-A", 25));
	mapOfStudentCount.insert(pair<string, int> ("Div-B", 50));
	mapOfStudentCount.insert(pair<string, int> ("Div-C", 75));

	map<string, int>::reverse_iterator it = mapOfStudentCount.rbegin();

	string div;
	int count;
	while(it != mapOfStudentCount.rend())
	{
		div = it -> first;
		count = it -> second;

		cout<<div<<" :: "<<count<<endl;

		it++;
	}

	return 0;
}

/*Output:
Div-C :: 75
Div-B :: 50
Div-A :: 25
*/
