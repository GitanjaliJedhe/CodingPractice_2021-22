// Searching element in std::map by value

#include <iostream>
#include <map>
#include <string> 

using namespace std;

map<string, int>::iterator searchByValue(map<string, int> &teleDir, int teleNum)
{
	map<string, int>::iterator it = teleDir.begin();
	while(it != teleDir.end())
	{
		if(it->second == teleNum)
		{
			return it;
		}
		it++;
	}
}

int main()
{
	map<string, int> telephoneDirectory;

	telephoneDirectory.insert(make_pair("Gitanjali Jedhe", 952112));
	telephoneDirectory.insert(make_pair("Snehal Jedhe", 962112));
	telephoneDirectory.insert(make_pair("Rushali Jedhe", 972112));

	map<string, int>::iterator it = searchByValue(telephoneDirectory, 952112);

	if(it != telephoneDirectory.end())
	{
		cout<<it -> first<<"::"<<it->second<<endl;
	}

	return 0;
}

/*Output:
Gitanjali Jedhe::952112
*/
