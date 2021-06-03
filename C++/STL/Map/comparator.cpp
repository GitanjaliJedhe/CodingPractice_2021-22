// Map and External Sorting Criteria / Comparator

#include <iostream>
#include <map>
#include <string> 

using namespace std;

struct WordGreaterComparator
{
	bool operator () (const string &left, const string &right) const
	{
		return (left > right);
	}
};

int main()
{
	cout<<"Default sorting criteria for keys i.e operator < for std::string"<<endl;
	map<string, int> telephoneDirectory_1;

	telephoneDirectory_1.insert(pair<string, int>("Gitanjali Jedhe", 952112));
	telephoneDirectory_1.insert(pair<string, int>("Snehal Jedhe", 962112));
	telephoneDirectory_1.insert(pair<string, int>("Rushali Jedhe", 972112));

	map<string, int>::iterator itr;
	for(itr = telephoneDirectory_1.begin(); itr != telephoneDirectory_1.end(); itr++) 
	{
		cout<<itr -> first<<" "<<itr -> second<<endl;
	}

	cout<<"\nExternal sorting criteria for keys"<<endl;
	map<string, int, WordGreaterComparator> telephoneDirectory_2;

	telephoneDirectory_2.insert(pair<string, int>("Gitanjali Jedhe", 952112));
	telephoneDirectory_2.insert(pair<string, int>("Snehal Jedhe", 962112));
	telephoneDirectory_2.insert(pair<string, int>("Rushali Jedhe", 972112));

	for(itr = telephoneDirectory_2.begin(); itr != telephoneDirectory_2.end(); itr++) 
	{
		cout<<itr -> first<<" "<<itr -> second<<endl;
	}


	/* Compile Time Error as two std::map objects have different sorting criteria 
	if(telephoneDirectory_1 == telephoneDirectory_2)
	{
		cout<<"Maps are same"<endl;
	}*/

	return 0;
}

/*Output:
Default sorting criteria for keys i.e operator < for std::string
Gitanjali Jedhe 952112
Rushali Jedhe 972112
Snehal Jedhe 962112

External sorting criteria for keys
Snehal Jedhe 962112
Rushali Jedhe 972112
Gitanjali Jedhe 952112
*/
