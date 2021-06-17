// Different ways to initialize an unordered map

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	//Initializer List
	unordered_map<string, string> mapOfStateCapital_1(
			{
			{"Gujrat", "Gandhinagar"},
			{"Rajasthan","Jaipur"},
			{"Bihar", "Patna"}
			});

	for(pair<string, string> element : mapOfStateCapital_1)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}
	cout<<"***********************************************************************\n"<<endl;

	
	//Range of elements
	unordered_map<string, string> mapOfStateCapital_2(mapOfStateCapital_1.begin(), mapOfStateCapital_1.end());

	for(pair<string, string> element : mapOfStateCapital_2)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}
	cout<<"***********************************************************************\n"<<endl;

	//Other unordered_map
	unordered_map<string, string> mapOfStateCapital_3(mapOfStateCapital_1);

	for(pair<string, string> element : mapOfStateCapital_2)
	{
		cout<<element.first<<" :: "<<element.second<<endl;
	}
	cout<<"***********************************************************************\n"<<endl;

	return 0;
}

/*Output:
Bihar :: Patna
Gujrat :: Gandhinagar
Rajasthan :: Jaipur
***********************************************************************

Rajasthan :: Jaipur
Bihar :: Patna
Gujrat :: Gandhinagar
***********************************************************************

Rajasthan :: Jaipur
Bihar :: Patna
Gujrat :: Gandhinagar
***********************************************************************
*/
