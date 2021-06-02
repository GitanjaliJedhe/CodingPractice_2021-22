// Introduction of std::map

#include <iostream>
#include <map>
#include <string> 

using namespace std;

int main()
{
	map<string, int> telephoneDirectory;

	telephoneDirectory.insert(pair<string, int>("Gitanjali Jedhe", 952112));
	telephoneDirectory.insert(pair<string, int>("Snehal Jedhe", 962112));
	telephoneDirectory.insert(pair<string, int>("Rushali Jedhe", 972112));

	map<string, int>::iterator itr;
	for(itr = telephoneDirectory.begin(); itr != telephoneDirectory.end(); itr++) 
	{
		cout<<itr -> first<<" "<<itr -> second<<endl;
	}


	telephoneDirectory["Chaitrali Jedhe"] = 982112;

	telephoneDirectory["Gitanjali Jedhe"] = 992112; // Replace the value of already added key i.e "Gitanjali Jedhe"

	if(telephoneDirectory.insert(pair<string, int>("Gitanjali Jedhe", 999999)).second == false) // Not replace already added key instead it returns if element is added or not 
	{
		cout<<"Element with key 'Gitanjali Jedhe' not inserted because already existed"<<endl;
	}

	if(telephoneDirectory.find("Gitanjali Jedhe") != telephoneDirectory.end())
	{
		cout<<"Record for 'Gitanjali Jedhe' found"<<endl;
	}

	if(telephoneDirectory.find("Prath Jedhe") == telephoneDirectory.end())
	{
		cout<<"Record for 'Prathm Jedhe' found"<<endl;
	}

	return 0;
}

/*Output:
Gitanjali Jedhe 952112
Rushali Jedhe 972112
Snehal Jedhe 962112
Element with key 'Gitanjali Jedhe' not inserted because already existed
Record for 'Gitanjali Jedhe' found
Record for 'Prathm Jedhe' found
*/
