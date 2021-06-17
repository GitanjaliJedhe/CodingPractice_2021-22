// Erasing an element from unordered_map by key  

#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, string> mapOfStateCapital;

	mapOfStateCapital.insert(pair<string, string> ("Maharashtra", "Mumbai"));
	mapOfStateCapital.insert(pair<string, string> ("West Bengal", "Kolkata"));
	mapOfStateCapital.insert(pair<string, string> ("Harayana", "Chandigarh"));


	if(mapOfStateCapital.erase("West Bengal") == 1)
	{
		cout<<"Element Deleted"<<endl;
	}

	return 0;
}

/*Output:
Element Deleted

*/
