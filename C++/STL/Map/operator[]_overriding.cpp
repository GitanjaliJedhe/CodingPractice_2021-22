// Overriding values with operator []

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

	// There is no element with key 'Ladak'
	// operator [] will create a new element in map
	// with key as 'Ladak' and default value, which in this case will be 0
	int &value_1 = mapOfStatePopulation["Ladak"];
	cout<<"Value of 'Ladak' = "<<value_1<<endl;

	// Fetch the value for key 'Maharashtra'
	// as key already exist therefore will not create new entry
	// will just return the reference of value
	int &value_2 = mapOfStatePopulation["Maharashtra"];
	cout<<"Value of 'Maharashtra' = "<<value_2<<endl;

	// Override the value
	mapOfStatePopulation["Goa"] = 70000;
	int &value_3 = mapOfStatePopulation["Goa"];
	cout<<"Value of 'Goa' = "<<value_3<<endl;

	mapOfStatePopulation["Assam"] = 450000;

	cout<<"************Map Entries************"<<endl;
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
