//std::map           Balance BST
//std::unordered_map Hashing Table

/*When to choose map instead of unordered_map
 * 1) When you need Low Memory
 * 2) When you are interested in sorted order 
 * 3) When need guaranted performance O(log N)
 * 
 *When to choose unordered_map instead of map
 * 1) When you have good hasher and no memory limitation
 * */

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main() 
{
	map<string, string> mapOfStateCapital_1;

	mapOfStateCapital_1.insert(pair<string, string> ("Maharashtra", "Mumbai"));
	mapOfStateCapital_1.insert(pair<string, string> ("Gujarat", "Gandhinagar"));
	mapOfStateCapital_1.insert(pair<string, string> ("Bihar", "Patana"));
	mapOfStateCapital_1.insert(pair<string, string> ("Punjab", "Chandigarh"));
	mapOfStateCapital_1.insert(pair<string, string> ("Tamil Nadu", "Chennai"));

	cout<<"Elements are in sorted order"<<endl;
	for_each(mapOfStateCapital_1.begin(), mapOfStateCapital_1.end(), [] (pair<string, string> elem)
				{
					cout<<elem.first<<" :: "<<elem.second<<endl;
				});



	unordered_map<string, string> mapOfStateCapital_2;

	mapOfStateCapital_2.insert(pair<string, string> ("Maharashtra", "Mumbai"));
	mapOfStateCapital_2.insert(pair<string, string> ("Gujarat", "Gandhinagar"));
	mapOfStateCapital_2.insert(pair<string, string> ("Bihar", "Patana"));
	mapOfStateCapital_2.insert(pair<string, string> ("Punjab", "Chandigarh"));
	mapOfStateCapital_2.insert(pair<string, string> ("Tamil Nadu", "Chennai"));

	cout<<"\nElements are in random order"<<endl;
	for_each(mapOfStateCapital_2.begin(), mapOfStateCapital_2.end(), [] (pair<string, string> elem)
				{
					cout<<elem.first<<" :: "<<elem.second<<endl;	
				});

	return 0;
}

/*Memory Usage:
 * 	Memory usage is more in unordered_map as compared to map because unordered_map need space for storing hash table
 *Time Complexity:
 	std::map O(log n) because element stored internally as Balanced Binary Search Tree
	std::unordered_map best case is O(1) and if hash code function is not good then, worst case complexitiy is O(n)
 * */

/*Output:
Elements are in sorted order
Bihar :: Patana
Gujarat :: Gandhinagar
Maharashtra :: Mumbai
Punjab :: Chandigarh
Tamil Nadu :: Chennai

Elements are in random order
Tamil Nadu :: Chennai
Maharashtra :: Mumbai
Gujarat :: Gandhinagar
Punjab :: Chandigarh
Bihar :: Patana
*/
