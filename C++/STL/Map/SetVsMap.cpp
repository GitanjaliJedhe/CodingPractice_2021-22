/*When to choose SET and when MAP?
 * If you want to maintain data structure of unique keys only without any associated value that plan to modify in future then use Set.
 * If you want to modify any element in set then erase it and insert the new one.
 * Whereas, use map if you want to maintain a data structure of unique keys and some associated value with each key that you want to change in future.  
 * */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm> // for_each()
#include <iterator>

using namespace std;

/*Set:
 * 1) Set is associative container which we need to store unique elements
 * 2) It always keep elements in sorted order
 * 3) Internally it maintains a balanced binary search tree of elements. Therefore when we Search an element 
 *    inside the set then it take only log(n) complexity to search it.
 * 4) Element added inside the set is const. because if you could modify the the element, then it would hamper
 *    set's internal data structure i.e it will lose its internal balanced binary search tree property and results 
 *    in undefined behaviour.
 * */

void setExample()
{
	set<string> setOfStudents;

	setOfStudents.insert("Gitanjali");
	setOfStudents.insert("Snehal");
	setOfStudents.insert("Rushali");

	for_each(setOfStudents.begin(), setOfStudents.end(), [] (string elem)
		 {
		 	cout<<elem<<" , ";
		 });
	cout<<endl;

	// Try to change element
	set<string>::iterator it = setOfStudents.find("Gitanjali");

	if(it != setOfStudents.end())
	{
		//*it = "Jedhe"; NOT ALLOWED
		cout<<*it<<endl;
	}
}

/*Map:
 * 1) Map is a associative container that is used to store key-value pair of elements with unique keys
 * 2) It always keeps the inserted pairs in sorted order based on the key
 * 3) Internally it maintains a balanced binary search tree to store keys. Therefore when searching key inside
 *    the map takes only log(n) complexity
 * 4) We cannot modify the key of any inserted pair in map
 * 5) We can modify the value associated with key
 * */

void mapExample()
{
	map<string, int> mapOfStudents;

	mapOfStudents.insert(make_pair("Gitanjali", 999));
	mapOfStudents.insert(make_pair("Snehal", 888));
	mapOfStudents.insert(make_pair("Rushali", 777));

	map<string, int>::iterator it = mapOfStudents.find("Gitanjali");
	if(it != mapOfStudents.end())
	{
		cout<<"Name := "<<it->first<<" :: RollNo := "<<it->second<<endl;
		//it -> first = "Git"; NOT ALLOWED
		it -> second = 111;
	}
}

int main()
{
	setExample();

	mapExample();

	return 0;
}

/*Output:
Gitanjali , Rushali , Snehal ,
Gitanjali
Name := Gitanjali :: RollNo := 999
*/
