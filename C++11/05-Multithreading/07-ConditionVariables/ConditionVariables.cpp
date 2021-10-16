#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

class Application
{
    private:
        std::mutex m_mutex;
        bool m_bDataLoaded;
        std::condition_variable m_condVar;

    public:
        Application()
        {
            m_bDataLoaded = false;
        }

        void loadData()
        {
            // Make this thread sleep for 1 second
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout<<"Loading data from XML"<<std::endl;

            // Lock the data structure
            std::lock_guard<std::mutex> guard(m_mutex);

            // Set the flag to true, means data is loaded
            m_bDataLoaded = true;

            // Notify the condition variable
            m_condVar.notify_one();
        }
    
        bool isDataLoaded()
        {
            return m_bDataLoaded;
        }

        void mainTask()
        {
            std::cout<<"Do some handshaking"<<std::endl;
        
            // Acquire the lock
            std::unique_lock<std::mutex> mlock(m_mutex); 

            // Start waiting for the Condition Variable to get signaled
            // Wait() will internally release the lock and make the thread to block 
            // As soon as condition variable get signaled, resume the thread and
            // again acquire the lock. Then check if condition is met or not  
            // If condition is met then continue else again go in wait.
            m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));

            // Do processing on loaded data
            std::cout<<"Do processing on loaded data"<<std::endl;
        }
};

int main()
{
    Application app;

    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::loadData, &app);

    thread_2.join();
    thread_1.join();

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/07-ConditionVariables$ g++ ConditionVariables.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/07-ConditionVariables$ ./a.out
Do some handshaking
Loading data from XML
Do processing on loaded data
*/

