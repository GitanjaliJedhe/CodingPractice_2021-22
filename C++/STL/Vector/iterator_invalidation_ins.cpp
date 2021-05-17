#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec;

	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	for(auto it = vec.begin(); it != vec.end(); it++)
	{
		cout<<(*it)<<" , ";
	}
	cout<<endl;
	
	auto it = vec.begin();
	vec.insert(it+2, 1, 300);
	it = vec.begin();

	for(; it != vec.end(); it++)
		cout<<(*it)<<" , ";

	exit(0);
}
