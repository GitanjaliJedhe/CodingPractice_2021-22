// Erasing an elements while iterating in loop  

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
	mapOfStateCapital.insert(pair<string, string> ("Madhya Pradesh", "Bhopal"));

	unordered_map<string, string>::iterator it = mapOfStateCapital.begin();

	while(it != mapOfStateCapital.end())
	{
		if(it -> first[0] == 'M') 
		{
			it = mapOfStateCapital.erase(it);
		}
		else
			it++;
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
