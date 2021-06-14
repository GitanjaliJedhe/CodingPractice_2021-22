// Erase map elements by Value

#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename K, typename V>
int erase_if(map<K, V> &mapOfStatePop, V value)
{
	int totalDeletedElements = 0;
	auto it = mapOfStatePop.begin();
	while(it != mapOfStatePop.end())
	{
		if(it -> second == value)
		{
			totalDeletedElements++;
			// Erase the current element, erase() will return the next iterator.
			// So, don't need to increment
			it = mapOfStatePop.erase(it);
		}
		else
		{
			it++;
		}
	}
	return totalDeletedElements;
}

int main()
{
	map<string, int> mapOfStatePopulation;

	mapOfStatePopulation.insert(pair<string, int> ("Maharashtra", 900000));
	mapOfStatePopulation.insert(pair<string, int> ("Keral", 80000));
	mapOfStatePopulation.insert(pair<string, int> ("Rajasthan", 600000));
	mapOfStatePopulation.insert(pair<string, int> ("Goa", 80000));
	mapOfStatePopulation.insert(pair<string, int> ("Bihar", 1000000));

	cout<<"Map entries before deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	int population = 80000;
	int totalDeletedElements = erase_if(mapOfStatePopulation, population);
	cout<<"\nTotal elements deleted "<<totalDeletedElements<<endl;

	cout<<"\nMap entries after deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	return 0;
}

/*Output:
Map entries before deletion
Bihar :: 1000000
Goa :: 80000
Keral :: 80000
Maharashtra :: 900000
Rajasthan :: 600000

Total elements deleted 2

Map entries after deletion
Bihar :: 1000000
Maharashtra :: 900000
Rajasthan :: 600000
*/
