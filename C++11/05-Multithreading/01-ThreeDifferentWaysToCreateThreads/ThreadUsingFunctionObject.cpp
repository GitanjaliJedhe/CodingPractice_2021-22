#include <iostream>
#include <thread>

class DisplayThread
{
    public:
        void operator()()
        {
            for(int i = 0; i < 1000; i++)
                std::cout<<"Inside thread"<<std::endl;
        }
};

int main()
{
    std::thread threadObj((DisplayThread()));
    
    for(int i = 0; i < 1000; i++)
        std::cout<<"Inside mainthread"<<std::endl;

    std::cout<<"Waiting for thread to complete"<<std::endl;
    threadObj.join();
    std::cout<<"Exiting from main thread"<<std::endl;

    return 0;
}

/*Output:-)
g++ -std=c++11 ThreadUsingFunctionObject.cpp -lpthread
./a.out
*/
