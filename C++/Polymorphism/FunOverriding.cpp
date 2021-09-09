#include <iostream>

using namespace std;

class Base
{
	public:
		virtual void print()
		{
			cout<<"Base class print"<<endl;
		}
		void show()
		{
			cout<<"Base class show"<<endl;
		}
};

class Derived : public Base
{
	public:
		void print()
		{
			cout<<"Derived class print"<<endl;
		}
		void show()
		{
			cout<<"Derived class show"<<endl;
		}
};

int main()
{
	Base *bptr;
	Derived dobj;
	bptr = &dobj;
	
	// Virtual function, binded at run time
	bptr->print();
	// Non-virtual function, binded at compile time
	bptr->show();

	exit(0);
}
