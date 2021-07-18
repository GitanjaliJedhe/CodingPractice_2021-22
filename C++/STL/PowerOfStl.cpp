// Find given point is lying in any interval

#include <iostream>
#include <set>
#include <iterator>
#include <limits.h>

using namespace std;

int main()
{
	set<pair<int, int>> setOfInt;

	setOfInt.insert({401, 450});
	setOfInt.insert({10, 20});
	setOfInt.insert({2, 3});
	setOfInt.insert({30, 400});

	//All elemens are stored in a sorted order
	//2, 3
	//10, 20
	//30, 400
	//401, 450
	
	int point = 15;

	auto it = setOfInt.upper_bound({point, INT_MAX});
	if(it == setOfInt.begin())
	{
		cout<<"the given point is not lying in any interval"<<endl;
		return 1;
	}

	it--;

	pair<int, int> current = *it;
	if(current.first <= point && point <= current.second)
	{
		cout<<"Yes its present: "<<current.first<<" "<<current.second<<endl;
	}
	else
	{
		cout<<"the given point is not lying in any interval"<<endl;
	}

	return 0;
}

/*Output:
 * Yes its present: 10 20
 * */
