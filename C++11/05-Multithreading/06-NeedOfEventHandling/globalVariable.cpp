/* Disadvantages of using this method:
Thread will keep on acquiring the lock and release it just to check the value, therefore it will consume CPU cycles and will also make thread 1 slow, because it needs to acquire same lock to check the bool flag
Better mechanism to achieve this, Thread 1 just block by waiting for an event to get signaled and another Thread could signal that Event and make Thread 1 continue. It would have save many CPU cycles and gave better performance.
*/

#include <iostream>
#include <thread>
#include <mutex>

class Application
{
    private:
        std::mutex m_mutex;
        bool m_bDataLoaded;

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
        }
    
        void mainTask()
        {
            std::cout<<"Do some handshaking"<<std::endl;
        
            // Acquire the lock
            m_mutex.lock();

            // Check flag is set to true or not
            while(m_bDataLoaded != true)
            {
                // Release the lock
                m_mutex.unlock();
        
                // sleep for 100 milli seconds
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                
                // Acquire the lock
                m_mutex.lock();
            }

            // Release the lock
            m_mutex.unlock();

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
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/06-NeedOfEventHandling$ g++ globalVariable.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/06-NeedOfEventHandling$ ./a.out
Do some handshaking
Loading data from XML
Do processing on loaded data
*/

