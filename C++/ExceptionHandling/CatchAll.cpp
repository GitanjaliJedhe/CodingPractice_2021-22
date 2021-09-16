#include <iostream>

int main()
{
    int x = -1;

    try
    {
        if(x < 0)
        {
            throw x;
        }
    }
    catch (char c)
    {
        std::cout<<"Exception Caught"<<std::endl;
    }
    catch(...)
    {
        std::cout<<"Default Exception"<<std::endl;
    }
    return 0;
}

/*Output:-)
Default Exception
*/
