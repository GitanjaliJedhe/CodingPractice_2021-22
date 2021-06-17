// Unordered_Map internally uses hashing
// Unordered_Map elements are stored in arbitrary order
// Advantage of using unordered_map instead of associative map is searching efficiency. 
// Unordered_Map complextiy to search for an element is O(1) if hash code are chosen efficiently.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, string> mapOfStateCapital;

	mapOfStateCapital.insert(pair<string, string> ("Maharashtra", "Mumbai"));
	mapOfStateCapital.insert(pair<string, string> ("Assam", "Dispur"));
	mapOfStateCapital.insert(pair<string, string> ("Goa", "Panaji"));

	for(pair<string, string> elem : mapOfStateCapital) 
	{
		cout<<elem.first<<" :: "<<elem.second<<endl;
	}

	return 0;
}

/*Output:
Goa :: Panaji
Assam :: Dispur
Maharashtra :: Mumbai
*/
