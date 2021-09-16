// Copy constructor is called when a new object is created from an existing object, as a copy of the existing object
// Assignment operator is called when an already initialized object is assigned a new value from another existing object

#include <iostream>
#include <stdio.h>

class Test
{
    public:
        Test() {}
        
        Test(const Test &)
        {
            std::cout<<"Copy constructor called"<<std::endl;
        }

        Test& operator =(const Test &t)
        {
            std::cout<<"Assignment operator called"<<std::endl;
            return *this;
        }
};

int main()
{
    Test t1, t2;
    t2 = t1; // Assignment operator called, same as "t2.operator=(t1);"
    
    Test t3 = t1; // Copy constructor called, same as "Test t3(t1);"
    return 0;
}

/*Output:-)
Assignment operator called
Copy constructor called
*/
