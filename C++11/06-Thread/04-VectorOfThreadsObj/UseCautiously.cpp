#include <iostream>
#include <thread>
#include <vector>
#include <functional> // For std::function

int main()
{
    // Create vector of threads
    std::vector<std::thread> vecOfThreads;

    std::function<void()> func = []() {
                                        // Do some important work
                                        // Print thread id 
                                        std::cout<<"Thread Id = "<<std::this_thread::get_id()<<std::endl;
                                    };

    // Add thread object to vector
    // We can also push std::thread without specifically specifying std::move(), if we pass them as rvalue
    vecOfThreads.push_back(std::thread(func));
    
    // Create 3 different thread object
    std::thread threadObj1(func);
    std::thread threadObj2(func);
    std::thread threadObj3(func);

    // Move 3 thread objects to vector
    // std::thread objects are move only i.e we cannot copy them, only move them. Therefore, we need to move these 3 thread objects in vector
    vecOfThreads.push_back(std::move(threadObj1));    
    vecOfThreads.push_back(std::move(threadObj2));    
    vecOfThreads.push_back(std::move(threadObj3));    

    std::thread threadObj4(func);

    // Destructor of already existing thread object will call terminate
    //vecOfThreads[1] = std::move(threadObj4);

    // First join the existing object
    if(vecOfThreads[1].joinable())
        vecOfThreads[1].join();

    vecOfThreads[1] = std::move(threadObj4);

    // Cannot copy vector of thread, COMPILE TIME ERROR 
    //std::vector<std::thread> newVecOfThreads = vecOfThreads;

    // Can only move vector of thread
    std::vector<std::thread> newVecOfThreads = std::move(vecOfThreads);


    // Wait for all threads in vector to join

    // Iterate over the vector
    // As vector contains various thread objects, so when this vector object is destructed it will call destructor of all the thread objects in the vector.
    // If any of the destructed thread object is joinable and not joined the std::terminate() will be called from its destrcutor. Therefore its necessary to join all the joinable threads in vector before vector is destructed.
    for(std::thread &th : newVecOfThreads)
    {
        // If thread object is joinable then join that thread
        if(th.joinable())
            th.join();
    }

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/04-VectorOfThreadsObj$ g++ UseCautiously.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/04-VectorOfThreadsObj$ ./a.out
Thread Id = 140581233288960
Thread Id = 140581241681664
Thread Id = 140581250074368
Thread Id = 140581258467072
Thread Id = 140581266859776
*/
