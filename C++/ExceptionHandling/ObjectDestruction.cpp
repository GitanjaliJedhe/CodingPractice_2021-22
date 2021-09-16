#include <iostream>

class Test
{
    public:
        Test()
        {
            std::cout<<"Constructor of Test"<<std::endl;
        }
        
        ~Test()
        {
            std::cout<<"Destructor of Test"<<std::endl;
        }
};

int main()
{
    try
    {
        Test t1;
        throw 10;
    }
    catch(int i)
    {
        std::cout<<"Caught "<<i<<std::endl;
    }

    return 0;
}

/*Output:-)
Constructor of Test
Destructor of Test
Caught 10
*/
