#include <iostream> // std::cerr
#include <typeinfo> // operator typeid
#include <exception> // std::exception

class Polymorphic
{
    virtual void member()
    {
    }   
};

int main()
{
    try
    {
        Polymorphic *pb = 0;
        typeid(*pb); // throws a bad_typeid exception
    }
    catch(std::exception& e)
    {
        std::cerr << "exception caught: "<<e.what()<<std::endl;
    }
    return 0;
}

/*Output:-)
exception caught: std::bad_typeid
*/
