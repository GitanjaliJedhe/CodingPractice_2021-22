#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class OddCounter
{
	private:
		int mCounter = 0;

	public:
		int getCount()
		{
			return mCounter;
		}

		void update(vector<int> &vect)
		{
			// Capturing member variable by value will not work
			// will result in Compiler Error
			//for_each(vect.begin(), vect.end(), [this](int element){}); 
			for_each(vect.begin(), vect.end(), [this](int element) {
				if(element % 2)
					mCounter++;
				}
				);
		}
};

int main()
{
	vector<int> vect = {12, 23, 42, 53, 100, 199};

	OddCounter counterObj;
	counterObj.update(vect);

	int count = counterObj.getCount();

	cout<<"Counter = "<<count<<endl;

	exit(0);
}
