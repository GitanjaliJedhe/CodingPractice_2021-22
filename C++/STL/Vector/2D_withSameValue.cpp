#include <iostream>
#include <vector>
#include <algorithm> //for_each()

using namespace std;

int main() {
	int rows = 4, columns = 4;
	int value = 999;
	vector<vector<int>> matrix(rows, vector<int> (columns, value));

	for_each(matrix.begin(),
		matrix.end(),
		[] (const auto &row) {
		for_each(row.begin(),
			 row.end(),
			 [] (const auto &elem) {
			 cout<<elem<<" , ";
			 });
		cout<<endl;
		});

	return 0;
}
