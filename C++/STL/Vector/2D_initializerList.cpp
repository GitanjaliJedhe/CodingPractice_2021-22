#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<vector<int>> matrix = {  {1, 2, 3, 4, 5},
					{6, 7, 8, 9, 10},
					{11, 12, 13, 14, 15},
					{16, 17, 18, 19, 20}
					};

	for_each(matrix.begin(),
		matrix.end(),
		[] (const auto &vec) {
		for_each(vec.begin(),
			vec.end(),	
			[] (const auto &elem) {
			cout<<elem<<" , ";
			});
		cout<<endl;
		});

	exit(0);
}
