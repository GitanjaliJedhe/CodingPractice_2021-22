#include <iostream>
#include <thread>

int main()
{
    std::thread threadObj([] {
                        for(int i = 0; i < 1000; i++)
                            std::cout<<"Inside thread"<<std::endl;
                        });

    for(int i = 0; i < 1000; i++)
    {
        std::cout<<"Inside main thread"<<std::endl;
    }
    
    threadObj.join();

    std::cout<<"Exiting from mainthread"<<std::endl;

    return 0;
}
