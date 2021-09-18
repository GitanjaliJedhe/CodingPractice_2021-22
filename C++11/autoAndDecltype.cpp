// decltype gives the type information at compile time
// typeid gives at runtime

// Program to demonstrate use of decltype in functions
#include <iostream>

template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

int main()
{
    std::cout<<findMin(98, 4.5)<<std::endl;
    std::cout<<findMin(6.7, 3.9)<<std::endl;
    return 0;
}

/*
4.5
3.9
*/
