// Erase map element by range iterator

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

	map<string, int>::iterator it_1 = mapOfStatePopulation.begin();

	map<string, int>::iterator it_2 = mapOfStatePopulation.begin();
	it_2++;
	it_2++;

	if(it_1 != mapOfStatePopulation.end() && it_2 != mapOfStatePopulation.end())
	{
		mapOfStatePopulation.erase(it_1, it_2);
		cout<<"\nElements removed"<<endl;
	}
	else
	{
		cout<<"\nKey not found"<<endl;
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

Elements removed

Map entries after deletion
Keral :: 800000
Maharashtra :: 900000
Rajasthan :: 600000
*/
