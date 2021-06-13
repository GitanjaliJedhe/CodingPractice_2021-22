// Overriding values with operator []

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Population
{
	int pop;

	Population()
	{
		this -> pop = 0;
	}

	Population(int pop)
	{
		this -> pop = pop;
	}
};

int main()
{
	map<string, Population> mapOfStatePopulation;

	mapOfStatePopulation.insert(pair<string, Population> ("Maharashtra", Population(900000)));
	mapOfStatePopulation.insert(pair<string, Population> ("Keral", Population(800000)));
	mapOfStatePopulation.insert(pair<string, Population> ("Rajasthan", Population(600000)));
	mapOfStatePopulation.insert(pair<string, Population> ("Goa", Population(80000)));
	mapOfStatePopulation.insert(pair<string, Population> ("Bihar", Population(1000000)));

	// Key is not in the map, operator[] will create new entry
	// with default value of value field. Therefore, will compile only if occurance struct has default constructor 
	Population pop = mapOfStatePopulation["Odisa"];

	return 0;
}

/*Output:
*/
