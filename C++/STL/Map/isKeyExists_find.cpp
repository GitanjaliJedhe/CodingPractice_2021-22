// Check if given key exists in a map 

#include <iostream>
#include <map>
#include <string> 
#include <algorithm>

using namespace std;

int main()
{
	map<string, int> mapOfStudentsCount;

	mapOfStudentsCount.insert(pair<string, int>("F.Y.", 100));
	mapOfStudentsCount.insert(pair<string, int>("S.Y.", 50));
	mapOfStudentsCount.insert(pair<string, int>("T.Y.", 25));

	map<string, int>::iterator it = mapOfStudentsCount.find("S.Y.");

	if(it != mapOfStudentsCount.end())
	{
		cout<<"'S.Y.' students count found"<<endl;
		string year = it -> first;
		int count = it -> second;
		cout<<"key :: "<<year<<" value :: "<<count<<endl;
	}	
	else
	{
		cout<<"'S.Y.' students count not found"<<endl;
	}

	return 0;
}

/*Output:
'S.Y.' students count found
key :: S.Y. value :: 50
*/
