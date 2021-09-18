#include <iostream>

int main()
{
    int x = 5;
 
    // y will be of type int : data type of x   
    decltype(x) y = x+8;

    std::cout<<typeid(y).name()<<std::endl;

    return 0;
}

/*Output:-)
i
*/
