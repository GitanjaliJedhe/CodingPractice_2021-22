#include <iostream>

class SmartPtr
{
    private:
        int *ptr;

    public:
        // Constructor
        explicit SmartPtr(int *p = NULL) { ptr = p; }
        // Destructor
        ~SmartPtr() { delete ptr; }
        // Overloading dereferencing operator
        int& operator *() { return *ptr; }
        
};

int main()
{
    SmartPtr ptr(new int());
    *ptr = 999;
    std::cout<<*ptr<<std::endl;
    // We don't need to call the delete pointer: when object ptr goes out of scope
    // the destructor for it is automatically called and destructor does delete ptr.
    return 0;
}

/*Output:-)
999
*/
