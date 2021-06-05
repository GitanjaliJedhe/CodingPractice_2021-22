// pair<iterator, bool> insert(const value_type& element)

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm> // for_each

using namespace std;

// function to check insertion is successful or not 
void testResult(pair<map<string, int>::iterator, bool> &result)
{
	if(result.second == false)
	{
		// Insertion Failed
		cout<<"Failed to add . duplicate key :: "<<result.first->first<<endl;
	} 
	else
	{
		// Insertion Successful
		cout<<"Successful in Adding , key :: "<<result.first->first<<endl;
	}
}

int main()
{
	map<string, int> mapOfEmployeeCount;

	pair<map<string, int>::iterator, bool> result;

	result = mapOfEmployeeCount.insert(pair<string, int>("IB", 150));
	testResult(result);

	result = mapOfEmployeeCount.insert(pair<string, int>("RAW", 450));
	testResult(result);

	result = mapOfEmployeeCount.insert(pair<string, int>("CBI", 250));
	testResult(result);
	
	result = mapOfEmployeeCount.insert(pair<string, int>("RAW", 450));
	testResult(result);


	cout<<"\n*********************************************"<<endl;
	for_each(mapOfEmployeeCount.begin(), mapOfEmployeeCount.end(), 
			[] (pair<string, int> elem)
			{
				cout<<elem.first<<" :: "<<elem.second<<endl;
			});
	return 0;
}

/*Output:
Successful in Adding , key :: IB
Successful in Adding , key :: RAW
Successful in Adding , key :: CBI
Failed to add . duplicate key :: RAW

*********************************************
CBI :: 250
IB :: 150
RAW :: 450
*/
