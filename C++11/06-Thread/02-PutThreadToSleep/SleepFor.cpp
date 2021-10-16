// Sleep for a Duration

#include <iostream>
#include <thread>
#include <chrono>

void threadFun()
{
    for(int i = 0; i < 10; i++)
    {
        std::cout<<std::this_thread::get_id()<<" :: "<<i<<std::endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread threadObject(threadFun);
    
    threadObject.join();    

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/02-PutThreadToSleep$ g++ SleepFor.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/02-PutThreadToSleep$ ./a.out 
140142657070848 :: 0
140142657070848 :: 1
140142657070848 :: 2
140142657070848 :: 3
140142657070848 :: 4
140142657070848 :: 5
140142657070848 :: 6
140142657070848 :: 7
140142657070848 :: 8
140142657070848 :: 9
*/

