// Deleting data from std::map

#include <iostream>
#include <map>
#include <string> 

using namespace std;

int main()
{
	map<string, int> telephoneDirectory;

	telephoneDirectory.insert(make_pair("Gitanjali Jedhe", 952112));
	telephoneDirectory.insert(make_pair("Snehal Jedhe", 962112));
	telephoneDirectory.insert(make_pair("Rushali Jedhe", 972112));

	telephoneDirectory["Chaitrali Jedhe"] = 982112;

	// Erasing by iterator
	map<string, int>::iterator it = telephoneDirectory.find("Chaitrali Jedhe");
	telephoneDirectory.erase(it);

	// Erasing by key
	telephoneDirectory.erase("Rushali Jedhe");	

	it = telephoneDirectory.begin();
	while(it != telephoneDirectory.end())
	{
		cout<<it->first<<"::"<<it->second<<endl;
		it++;
	}

	return 0;
}

/*Output:
Gitanjali Jedhe::952112
Snehal Jedhe::962112

*/
