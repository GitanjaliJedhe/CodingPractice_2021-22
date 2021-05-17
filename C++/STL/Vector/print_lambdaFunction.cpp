#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// create vector of integers
	vector<int> vec_of_int{1, 2, 3, 4, 5};

	for_each(vec_of_int.begin(),
		 vec_of_int.end(),
		 [](const auto &elem) {cout<<elem<<" , ";} //lambda function
		 );

	int sum = 0;
	for_each(vec_of_int.begin(),
		 vec_of_int.end(),
		 [&sum](const auto &elem) {
		 	sum =sum + elem;} //lambda function
		 );
	cout<<"\nTotal: "<<sum<<endl;

	return 0;
}
