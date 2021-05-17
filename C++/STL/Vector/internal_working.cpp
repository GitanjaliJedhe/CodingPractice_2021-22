#include <iostream>
#include <vector>

using namespace std;

struct Sample
{
	Sample() {}
	Sample(const Sample &obj)
	{
		cout<<"Sample copy constructor"<<endl;
	}
};

int main()
{
	vector<Sample> vecOfInts;

	cout<<"Capacity = "<<vecOfInts.capacity()<<endl;
	cout<<"Size = "<<vecOfInts.size()<<endl;

	int capacity = vecOfInts.capacity();
	for(int i = 0; i < capacity + 1; i++)
	{
		vecOfInts.push_back(Sample());
	}

	cout<<"Capacity = "<<vecOfInts.capacity()<<endl;
	cout<<"Size = "<<vecOfInts.size()<<endl;
	
	for(int i = 0; i < capacity + 1; i++)
	{
		vecOfInts.push_back(Sample());
	}

	cout<<"Capacity = "<<vecOfInts.capacity()<<endl;
	cout<<"Size = "<<vecOfInts.size()<<endl;
}

