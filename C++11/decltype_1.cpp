#include <iostream>

int fun1() { return 10;};
char fun2() {return 'c';};

int main()
{
    // Datatype of x is same as return type of fun1()
    // Datatype of y is same as return type of fun2()
    decltype(fun1()) x;
    decltype(fun2()) y;

    std::cout<<typeid(x).name()<<std::endl;
    std::cout<<typeid(y).name()<<std::endl;

    return 0;
}
/*Output:-)
i
c
*/
