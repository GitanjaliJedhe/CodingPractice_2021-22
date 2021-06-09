// Iterate over a map

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	map<string, int> mapOfStudentCount;

	mapOfStudentCount.insert(pair<string, int> ("Div-A", 25));
	mapOfStudentCount.insert(pair<string, int> ("Div-B", 50));
	mapOfStudentCount.insert(pair<string, int> ("Div-C", 75));

	// Iterate over a map using STL Iterator
	map<string, int>::iterator it = mapOfStudentCount.begin();

	string div;
	int count;
	while(it != mapOfStudentCount.end())
	{
		div = it -> first; 
		count = it -> second;

		cout<<div<<" :: "<<count<<endl;

		it++;
	}
	cout<<endl;	


	// Iterator over the map using C++11 range based for loop 
	for(pair<string, int> element : mapOfStudentCount)
	{
		div = element.first; 
		count = element.second;

		cout<<div<<" :: "<<count<<endl;
	}
	cout<<endl;

	// Iterator over a map using std::for_each() and Lambda function
	for_each(mapOfStudentCount.begin(), mapOfStudentCount.end(), [] (pair<string, int> element)
			{
				string div = element.first;
				int count = element.second;

				cout<<div<<" :: "<<count<<endl;
			});
	cout<<endl;

	return 0;
}

/*Output:
Div-A :: 25
Div-B :: 50
Div-C :: 75

Div-A :: 25
Div-B :: 50
Div-C :: 75

Div-A :: 25
Div-B :: 50
Div-C :: 75
*/
