// Searching in unordered_map  

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
		cout<<"Element found"<<endl;

		cout<<it->first<<" :: "<<it->second<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}

	return 0;
}

/*Output:
Element found
West Bengal :: Kolkata
*/
