#include <iostream>

// Here we specify the exceptions that this function throws
void fun(int *ptr, int x) throw (int *, int)
{
    if(ptr == NULL)
    {
        throw ptr;
    }
    if(x == 0)
    {
        throw x;
    }
}

int main()
{
    try
    {
        fun(NULL, 0);
    }
    catch(...)
    {
        std::cout<<"Caught exception from fun()"<<std::endl;
    }
    return 0;
}

/*Output:-)
Caught exception from fun()
*/
