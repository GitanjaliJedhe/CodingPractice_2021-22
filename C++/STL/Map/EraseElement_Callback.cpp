// Erase map elements by Callback

#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename K, typename V>
int erase_if(map<K, V> &mapOfStatePop, bool (*functor)(V))
{
	int totalDeletedElements = 0;
	auto it = mapOfStatePop.begin();
	while(it != mapOfStatePop.end())
	{
		if(functor(it -> second))
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

bool isOdd(int value)
{
	if(value % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	map<string, int> mapOfStatePopulation;

	mapOfStatePopulation.insert(pair<string, int> ("Maharashtra", 9456893));
	mapOfStatePopulation.insert(pair<string, int> ("Keral", 87534));
	mapOfStatePopulation.insert(pair<string, int> ("Rajasthan", 6642787));
	mapOfStatePopulation.insert(pair<string, int> ("Goa", 3672184));
	mapOfStatePopulation.insert(pair<string, int> ("Bihar", 2356129));

	cout<<"Map entries before deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	int totalDeletedElements = erase_if(mapOfStatePopulation, isOdd);
	cout<<"\nTotal elements deleted "<<totalDeletedElements<<endl;

	cout<<"\nMap entries after deletion"<<endl;
	for(auto elem : mapOfStatePopulation)
		cout<<elem.first<<" :: "<<elem.second<<endl;

	return 0;
}

/*Output:
Map entries before deletion
Bihar :: 2356129
Goa :: 3672184
Keral :: 87534
Maharashtra :: 9456893
Rajasthan :: 6642787

Total elements deleted 3

Map entries after deletion
Goa :: 3672184
Keral :: 87534
*/
