#include <iostream>

// A generic smart pointer class
template <class T>
class SmartPtr
{
    private:
        T *ptr;

    public:
        // Constructor
        explicit SmartPtr(T *p = NULL) { ptr = p; }
        
        // Destructor
        ~SmartPtr() { delete ptr; }

        // Overloading dereferencing operator
        T& operator *() { return *ptr; }
       
        // Overloading arrow operator so that 
        // members of T can be accessed like a pointer 
        T* operator ->() { return ptr; } 
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 999;
    std::cout<<*ptr<<std::endl;
    // We don't need to call the delete pointer: when object ptr goes out of scope
    // the destructor for it is automatically called and destructor does delete ptr.
    return 0;
}

/*Output:-)
999
*/
