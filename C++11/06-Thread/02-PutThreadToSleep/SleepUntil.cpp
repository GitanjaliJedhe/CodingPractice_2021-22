// Sleep Until a TimePoint

#include <iostream>
#include <thread>
#include <chrono>

void print_time_point(std::chrono::system_clock::time_point timePoint)
{
    std::time_t timeStamp = std::chrono::system_clock::to_time_t(timePoint);
    std::cout<<std::ctime(&timeStamp)<<std::endl;
} 

void threadFunc()
{
    std::cout<<"Current Time :: ";
    // Print Current Time 
    print_time_point(std::chrono::system_clock::now());

    // Create a time point pointing to 10 second in future
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now() + std::chrono::seconds(10);
    
    std::cout<<"Going to Sleep Until :: ";
    print_time_point(timePoint);

    // Sleep till specified time point
    // Accepts std::chrono::system_clock::time_point as argument
    std::this_thread::sleep_until(timePoint);

    std::cout<<"Current Time :: ";
    // Print current time
    print_time_point(std::chrono::system_clock::now());
}

int main()
{
    std::thread threadObj(threadFunc);
    
    threadObj.join();    

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/02-PutThreadToSleep$ g++ SleepUntil.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/02-PutThreadToSleep$ ./a.out 
Current Time :: Sun Sep 26 03:53:48 2021

Going to Sleep Until :: Sun Sep 26 03:53:58 2021

Current Time :: Sun Sep 26 03:53:58 2021
*/
