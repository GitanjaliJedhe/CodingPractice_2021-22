#include <iostream>

class Demo
{
    public:
        Demo()
        {
            std::cout<<"Constructor called"<<std::endl;
        }
        
        ~Demo()
        {
            std::cout<<"Destructor called"<<std::endl;
        }
};

int main()
{
    Demo obj1; // Constructor called
    
    if(1)
    {
        Demo obj2; // Constructor called
    } // Destructor called for obj2 
    
    return 0;
} // Destructor called for obj1

/*Output:-)
Constructor called
Constructor called
Destructor called
Destructor called
*/
