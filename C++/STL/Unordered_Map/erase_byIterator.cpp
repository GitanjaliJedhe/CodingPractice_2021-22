// Erasing an element from unordered_map through Iterator

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

	unordered_map<string, string>::iterator it = mapOfStateCapital.find("West Bengal");

	if(it != mapOfStateCapital.end())
	{
		mapOfStateCapital.erase(it);
		cout<<"Element Deleted\n"<<endl;
	}

	for(pair<string, string> element : mapOfStateCapital)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}

	return 0;
}

/*Output:
Element Deleted

Harayana :: Chandigarh
Maharashtra :: Mumbai
*/
