// Strongly-Typed enums. They are specified with the enum class keywords.

#include <iostream>

int main()
{
    // C++ 03
    /*enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday};
    enum Month {January, February, March, April, May, June, July, August, September, October, November, December};

    Day d = Monday;
    Month m = January;

    if(d == m)
    {   
        std::cout<<"Monday == January"<<std::endl;
    } 
    else
    {
        std::cout<<"Monday != January"<<std::endl;
    }*/  

    // C++ 11
    enum class Options {None, One, All};
    Options o = Options::All;
    
    enum class Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday};
    enum class Month {January, February, March, April, May, June, July, August, September, October, November, December};

    Day d = Day::Monday;
    Month m = Month::January;
 
    // No "==" operator is defined for the object type nor overloaded
    // So , in C++11, this is an compile time error 
    /*
    if(d == m)
    {
        std::cout<<"Monday == January"<<std::endl;
    }
    else
    {
        std::cout<<"Monday != January"<<std::endl;
    }*/
    
    return 0;
}

/*Output before:-)
g++ -std=c++03 StrongtypedEnum.cpp
./a.out
Monday != January
*/

/*Output after:-)
g++ -std=c++11 StrongtypedEnum.cpp
./a.out
*/
