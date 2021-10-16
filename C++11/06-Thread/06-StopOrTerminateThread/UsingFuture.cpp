#include <iostream>
#include <thread>
#include <chrono>
#include <future>

void thread_function(std::future<void> futureObj)
{
    std::cout<<"Thread Start"<<std::endl;

    while(futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
    {
        std::cout<<"Doing some work"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout<<"Thread End"<<std::endl;
}

int main()
{
    // Create std::promise object
    std::promise<void> exitSignal;

    // Fetch std::future object associated with promise
    std::future<void> futureObj = exitSignal.get_future();

    // Starting Thread & move the future object in lambda function by reference 
    std::thread threadObject(thread_function, std::move(futureObj)); 

    // Wait for 10 seconds
    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout<<"Asking thread to stop"<<std::endl;

    // Set the value in promise
    exitSignal.set_value();

    // wait for thread to join
    threadObject.join();

    std::cout<<"Exiting main()"<<std::endl;

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/06-StopOrTerminateThread$ g++ UsingFuture.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/06-StopOrTerminateThread$ ./a.out
Thread Start
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Doing some work
Asking thread to stop
Thread End
Exiting main()
*/
