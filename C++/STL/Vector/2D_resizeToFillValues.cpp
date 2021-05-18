#include <iostream>
#include <vector>
#include <algorithm> //for_each()

using namespace std; 

int main() {
	int rows = 4, columns = 3;
	int value = 11;

	vector<vector<int>> matrix;

	matrix.resize(rows, vector<int>(columns, value));

	for_each(matrix.begin(),
		matrix.end(),
		[] (const auto & row) {
		for_each(row.begin(),
			row.end(),
			[] (const auto &elem) {
				cout<<elem<<" , ";
			});
		cout<<endl;
		});

	return 0;
}
