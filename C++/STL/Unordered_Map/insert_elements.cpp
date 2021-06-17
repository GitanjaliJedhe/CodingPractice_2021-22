// Insert elements in unordered_map  

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

	
	typedef unordered_map<string, string>::iterator UOMIterator;
	pair<UOMIterator, bool> result = mapOfStateCapital.insert(make_pair<string, string> ("Kerala", "Thiruvananthapuram"));

	if(result.second == false)
	{
		cout<<"Element not inserted"<<endl;
	}
	else
	{
		cout<<"Element Inserted"<<endl;
		cout<<result.first->first<<" :: "<<result.first->second<<endl;
	}

	cout<<"\n*****************************************************************************************************"<<endl;
	for(pair<string, string> element : mapOfStateCapital)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}

	return 0;
}

/*Output:
Element Inserted
Kerala :: Thiruvananthapuram

*****************************************************************************************************
Kerala :: Thiruvananthapuram
Harayana :: Chandigarh
West Bengal :: Kolkata
Maharashtra :: Mumbai
*/
