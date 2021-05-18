#include <iostream>
#include <vector>
#include <algorithm> //for_each()

using namespace std;

int main()
{
	int rows = 5, columns = 5;
	vector<vector<int>> matrix(rows);

	int counter = 1;
	for(int r = 0; r < matrix.size(); r++) {
		for(int c = 0; c < columns; c++) {
			matrix[r].push_back((r + 1) * (c + 1));
		}
	}

	// Print 2D vector / matrix
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
