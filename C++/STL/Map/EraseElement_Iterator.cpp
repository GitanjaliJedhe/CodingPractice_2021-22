// Erase map element by iterator

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> mapOfStatePopulation;

	mapOfStatePopulation.insert(pair<string, int> ("Maharashtra", 900000));
	mapOfStatePopulation.insert(pair<string, int> ("Keral", 800000));
	mapOfStatePopulation.insert(pair<string, int> ("Rajasthan", 600000));
	mapOfStatePopulation.insert(pair<string, int> ("Goa", 80000));
	mapOfStatePopulation.insert(pair<string, int> ("Bihar", 1000000));

	cout<<"Map entries before deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	map<string, int>::iterator it = mapOfStatePopulation.find("Bihar");
	if(it != mapOfStatePopulation.end())
	{
		mapOfStatePopulation.erase(it);
		cout<<"\nElement with key 'Bihar' is deleted"<<endl;
	}
	else
	{
		cout<<"\nElement with key 'Bihar' is not found"<<endl;
	}

	cout<<"\nMap entries after deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	return 0;
}

/*Output:
Map entries before deletion
Bihar :: 1000000
Goa :: 80000
Keral :: 800000
Maharashtra :: 900000
Rajasthan :: 600000

Element with key 'Bhihar' is deleted

Map entries after deletion
Goa :: 80000
Keral :: 800000
Maharashtra :: 900000
Rajasthan :: 600000
*/
