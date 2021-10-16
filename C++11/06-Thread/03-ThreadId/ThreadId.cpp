#include <iostream>
#include <thread>
#include <assert.h>
#include <chrono>

void threadFunc()
{
    std::thread::id threadId = std::this_thread::get_id();
    std::cout<<"Inside thread :: thread id = "<<threadId<<std::endl;
}

int main()
{
    std::thread threadObj(threadFunc);

    std::thread::id threadId = threadObj.get_id();
    
    if(threadObj.joinable())
    {
        threadObj.join();
    }

    std::cout<<"Inside mainthread :: thread id = "<<threadId<<std::endl;

    // Fetching Thread Id from Detached thread
    std::thread dTHObj(threadFunc);

    // Detached thread
    dTHObj.detach();

    std::thread::id dThreadId = dTHObj.get_id();
    
    assert(dThreadId == std::thread::id());

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::cout<<"Inside mainthread :: detached thread id = "<<dThreadId<<std::endl;

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/03-ThreadId$ g++ ThreadId.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/03-ThreadId$ ./a.out 
Inside thread :: thread id = 140398723380992
Inside mainthread :: thread id = 140398723380992
Inside thread :: thread id = 140398723380992
Inside mainthread :: detached thread id = thread::id of a non-executing thread
*/
