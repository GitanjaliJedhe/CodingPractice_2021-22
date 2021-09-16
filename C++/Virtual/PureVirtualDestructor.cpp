// Provide function body for pure virtual destructor
// The reason is because destructors are not 'overridden'
// NOTE: Class becomes abstract class when it contains a pure virtual destructor.

#include <iostream>

class Base
{
    public:
        virtual ~Base() = 0; // pure virtual destructor 
};

Base::~Base()
{
    std::cout<<"Pure virtual destructor called"<<std::endl;
}

class Derived : public Base
{
    public:
        ~Derived()
        {
            std::cout<<"~Derived is executed"<<std::endl;
        }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

/*Output before :-( 
/usr/bin/ld: /tmp/cc8xxqqr.o: in function `Derived::~Derived()':
PureVirtualDestructor.cpp:(.text._ZN7DerivedD2Ev[_ZN7DerivedD5Ev]+0x4e): undefined reference to `Base::~Base()'
collect2: error: ld returned 1 exit status
*/

/*Output after :-)
~Derived is executed
Pure virtual destructor called
*/
