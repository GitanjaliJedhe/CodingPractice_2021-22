// Search by value in a map

#include <iostream>
#include <map>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

template <typename K, typename V>
bool findByValue(map<K, V> &mapOfStudCnt,V value, vector<K> &vec)
{
	bool result = false;
	auto it = mapOfStudCnt.begin();

	while(it != mapOfStudCnt.end())
	{
		if(it -> second == value)
		{
			result = true;
			vec.push_back(it -> first);
		}

		it++;
	}
	return result;
}

int main()
{
	map<string, int> mapOfEmployeeSalary;

	mapOfEmployeeSalary.insert(pair<string, int>("Gitanjali", 200000));
	mapOfEmployeeSalary.insert(pair<string, int>("Snehal", 200000));
	mapOfEmployeeSalary.insert(pair<string, int>("Rushali", 1500000));
	mapOfEmployeeSalary.insert(pair<string, int>("Aman", 200000));
	mapOfEmployeeSalary.insert(pair<string, int>("Dhruv", 1200000));

	int salary = 200000;

	vector<string> vec;

	bool result = findByValue(mapOfEmployeeSalary, salary, vec);	

	if(result == true)
	{
		cout<<"Keys with value "<<salary<<" are, "<<endl;
		for(auto elem : vec)
		{
			cout<<elem<<endl;
		}
	}
	else
	{
		cout<<"No key is found with the given value"<<endl;
	}

	return 0;
}

/*Output:
Keys with value 200000 are,
Aman
Gitanjali
Snehal
*/
