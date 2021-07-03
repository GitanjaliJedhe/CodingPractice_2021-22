// Set demo

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> iSet;

	iSet.insert(146);
	iSet.insert(576);
	iSet.insert(-45);
	iSet.insert(87);

	for(int elem : iSet)
	{
		cout<<elem<<" , ";
	}
	cout<<endl;

	set<int>::iterator it_1 = iSet.find(576);
	if(it_1 != iSet.end())
	{
		cout<<*it_1<<" is present"<<endl;
	}
	else
	{
		cout<<*it_1<<" is not present"<<endl;
	}

	set<int>::iterator it_2 = iSet.upper_bound(-45);
	cout<<"Upper bound : "<<*it_2<<endl;

	return 0;
}

/*Output:
-45 , 87 , 146 , 576 ,
576 is present
Upper bound : 87

*/
