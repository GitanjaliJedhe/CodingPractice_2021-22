// Erasing an element by value from unordered_map

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

	unordered_map<string, string>::iterator it = mapOfStateCapital.begin();

	while(it != mapOfStateCapital.end())
	{
		if(it -> second == "Mumbai")
			break;
		it++;
	}

	if(it != mapOfStateCapital.end())
	{
		mapOfStateCapital.erase(it);
	}

	for(pair<string, string> element : mapOfStateCapital)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}

	return 0;
}

/*Output:
Harayana :: Chandigarh
West Bengal :: Kolkata
*/
