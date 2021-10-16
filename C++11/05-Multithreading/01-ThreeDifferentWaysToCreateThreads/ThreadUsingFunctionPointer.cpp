#include <iostream>
#include <thread>

void thread_function()
{
    for(int i = 0; i < 1000; i++);
        std::cout<<"Inside thread function"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    
    for(int i = 0; i < 1000; i++);
        std::cout<<"Inside mainthread"<<std::endl;

    threadObj.join();
    std::cout<<"Exit from main function"<<std::endl;

    return 0;
}

/*Output :-)
g++ -std=c++11 ThreadUsingFunctionPointer.cpp -pthread
./a.out
Inside mainthread
Inside thread function
Exit main function  
*/

