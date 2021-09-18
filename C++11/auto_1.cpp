#include <iostream>

int main()
{
    //auto a; this line will give error because 'a' is not initialized at the time of declaration
    //a = 33;

    auto x = 4;
    auto y = 3.14;
    auto ptr = &x;

    std::cout<<typeid(x).name()<<std::endl;   // i for integer 
    std::cout<<typeid(y).name()<<std::endl;   // d for double
    std::cout<<typeid(ptr).name()<<std::endl; // Pi for pointer to integer

    return 0;
}

/*Output before :-(
auto_1.cpp: In function ‘int main()’:
auto_1.cpp:5:5: error: declaration of ‘auto a’ has no initializer
5 |     auto a;
|     ^~~~
*/

/*Output after :-)
i 
d
Pi 
*/
