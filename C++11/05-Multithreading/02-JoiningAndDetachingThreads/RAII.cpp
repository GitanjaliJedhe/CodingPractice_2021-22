// RESOURCE ACQUISITION IS INITIALIZATION (RIII)
#include <iostream>
#include <thread>

class ThreadRAII
{
    std::thread &m_thread;
    public:
        ThreadRAII(std::thread &threadObj) : m_thread(threadObj)
        {
            
        }

        ~ThreadRAII()
        {
            // check thread is joinable then detach the thread
            if(m_thread.joinable())
            {
                m_thread.detach();
            }
        }
};

void thread_function()
{
    for(int i = 0; i < 1000; i++);
        std::cout<<"Inside thread"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
       
    // If we comment this line, then program will crash 
    /ThreadRAII wrapperObj(threadObj);
    return 0;
}

