// A class is abstract if it has at least one pure virtual function

#include <iostream>

using namespace std;

class Base
{
    protected:
        int x;
    public:
        // Abstract class can have constructor
        Base(int i)
        {
            x = i;
            cout<<"Inside Base class Constructor"<<endl;   
        }
        virtual void show() = 0;
};

class Derived : public Base
{
    private:
        int y;
    public:
        Derived(int i, int j) : Base (i)
        {
            y = j;
        }
        void show()
        {
            cout<<"In Derived"<<endl;
        }
};

int main()
{
    //Base b; ERROR
    // We can have pointers and references of abstract class type
    Base *bp = new Derived(9, 4);
    bp->show();
    return 0;
}

/*Output before:-(
fact_1.cpp: In function ‘int main()’:
fact_1.cpp:24:10: error: cannot declare variable ‘b’ to be of abstract type ‘Base’
24 |     Base b;
|          ^
fact_1.cpp:7:7: note:   because the following virtual functions are pure within ‘Base’:
7 | class Base
|       ^~~~
fact_1.cpp:10:22: note:         ‘virtual void Base::show()’
10 |         virtual void show() = 0;
*/

/*Output after:-)
Inside Base class Constructor
In Derived
*/
