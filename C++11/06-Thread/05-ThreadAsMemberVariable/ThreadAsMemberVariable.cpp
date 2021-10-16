#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>

class ThreadWrapper
{
    private:
        std::thread threadHandler;

    public:
        // Delete copy constructor
        ThreadWrapper(const ThreadWrapper &) = delete;

        // Delete Assignment operator 
        ThreadWrapper& operator =(const ThreadWrapper &) = delete;

        // Parameterized Constructor
        ThreadWrapper(std::function<void()> func);

        
        // Move constructor
        ThreadWrapper(ThreadWrapper &&obj);

        // Move Assignment operator 
        ThreadWrapper& operator =(ThreadWrapper &&obj);

        // Destructor
        ~ThreadWrapper();
};

// Parameterized Constructor
ThreadWrapper::ThreadWrapper(std::function<void()> func) : threadHandler(func)
{}

// Move constructor
ThreadWrapper::ThreadWrapper(ThreadWrapper &&obj) : threadHandler(std::move(obj.threadHandler))
{
    std::cout<<"Move constructor is called"<<std::endl;
}

// Move Assignment operator 
ThreadWrapper& ThreadWrapper::operator =(ThreadWrapper &&obj)
{
    std::cout<<"Move Assignment operator called"<<std::endl;
    
    if(threadHandler.joinable())
        threadHandler.join();

    threadHandler = std::move(obj.threadHandler);
    return *this;
}

// Destructor
ThreadWrapper::~ThreadWrapper()
{
    if(threadHandler.joinable())
        threadHandler.join();
}

int main()
{
    std::function<void()> func = [] () {
    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Print thread id
    std::cout<<"Inside thread ThreadId = "<<std::this_thread::get_id()<<std::endl;
    };
    
    {
        // Create ThreadWrapper object
        // It will internally start the thread
        ThreadWrapper wrapper(func);

        // When wrapper will go out of scope, its destructor will be called
        // Which will internally join the member thread object
    }

    // Create vector of ThreadWrapper objects
    std::vector<ThreadWrapper> vecOfThreads;

    // Add ThreadWrapper objects in thread
    ThreadWrapper thwp1(func);
    ThreadWrapper thwp2(func);

    vecOfThreads.push_back(std::move(thwp1));
    vecOfThreads.push_back(std::move(thwp2));

    ThreadWrapper thwp3(func);

    // Change the content of vector
    vecOfThreads[1] = std::move(thwp3);

    // When vector will go out of scope, its destructor will be called, which will 
    // internally call the destructor all ThreadWrapper objects, which in tern
    // joins the member thread object.

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/05-ThreadAsMemberVariable$ g++ ThreadAsMemberVariable.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/05-ThreadAsMemberVariable$ ./a.out
Inside thread ThreadId = 140266115999488
Move constructor is called
Move constructor is called
Move constructor is called
Move Assignment operator called
Inside thread ThreadId = 140266099214080
Inside thread ThreadId = 140266107606784
Inside thread ThreadId = 140266115999488
*/
