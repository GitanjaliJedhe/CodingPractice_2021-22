#include <iostream>

// The override special identifier means that the compiler will check the base class(es) to see if 
// there is a virtual function with this exact signature. And if there is not, the compiler will indicate an error.

class Base
{
    public:
        virtual void fun();
};

class Derived : public Base
{ 
        // virtual void fun(int) override; Error
        virtual void fun() override;
};

int main()
{
    return 0;
}

/*Output before :-(
override.cpp:11:22: error: ‘virtual void Derived::fun(int)’ marked ‘override’, but does not override
11 |         virtual void fun(int i) override;
|                      ^~~
*/

/*Output after :-)
*/
