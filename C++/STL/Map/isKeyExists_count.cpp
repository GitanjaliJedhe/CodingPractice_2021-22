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

	if(mapOfStudentsCount.count("T.Y.") == 1)
	{
		cout<<"'T.Y.' students count found"<<endl;
	}	
	else
	{
		cout<<"'T.Y.' students count not found"<<endl;
	}

	return 0;
}

/*Output:
'T.Y.' students count found 
*/
