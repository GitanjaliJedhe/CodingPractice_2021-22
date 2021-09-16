// Making base class destructor virtual guarantees that the object of derived class is destructed properly
// As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor

#include <iostream>

class Base
{
    public:
        Base()
        {
            std::cout<<"Constructing Base"<<std::endl;
        }
        //~Base()
        virtual ~Base() // virtual destructor
        {
            std::cout<<"Destructing Base"<<std::endl;
        }
};

class Derived : public Base
{
    public:
        Derived()
        {
            std::cout<<"Constructing Derived"<<std::endl;
        }
        ~Derived()
        {
            std::cout<<"Destructing Derived"<<std::endl;
        }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    return 0;
}

/*Output before:-)
Constructing Base
Constructing Derived
Destructing Base
*/

/*Output after:-)
Constructing Base
Constructing Derived
Destructing Derived
Destructing Base
*/



