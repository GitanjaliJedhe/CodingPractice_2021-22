#include <iostream>
#include <thread>
#include <chrono>
#include <future>

/* 
Class that encapsulates promise and future object and 
provides API to set exit signal for the thread
*/

class Stoppable
{
    private:
        std::promise<void> exitSignal;
        std::future<void> futureObject;   

    public:
        Stoppable() : futureObject(exitSignal.get_future())
        {
        }

        Stoppable(Stoppable &&obj) : exitSignal(std::move(obj.exitSignal)), futureObject(std::move(obj.futureObject))
        {
            std::cout<<"Move constructor is called"<<std::endl;
        }

        Stoppable& operator =(Stoppable &&obj)
        {
            std::cout<<"Move Assignment is called"<<std::endl;
            exitSignal = std::move(obj.exitSignal);
            futureObject = std::move(obj.futureObject);
            return *this;
        }

        // Task need to provide defination for this function
        // It will be called by thread function
        virtual void run() = 0;

        // Thread function to be executed by thread
        void operator()()
        {
            run();
        }

        // Checks if  thread is requested to stop 
        bool stopRequested()
        {
            // Checks if value in future object is available
            if(futureObject.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout) 
                return false;
            return true;
        }

        // Request the thread to stop by setting value in promise object
        void stop()
        {
            exitSignal.set_value();
        }
};

// Task class that extends the Stoppable task
class MyTask : public Stoppable
{
    private:
        
    public:
        // Function to be executed by thread function
        void run()
        {
            std::cout<<"Task start"<<std::endl;

            // Check if thread is requested to stop
            while(stopRequested() == false)
            {
                std::cout<<"Doing some work"<<std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

            std::cout<<"Task end"<<std::endl;
        }
};

int main()
{
    MyTask task;
    
    // Creating thread to execute our task
    std::thread threadObj([&]()
    {
        task.run();
    });    

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout<<"Asking task to stop"<<std::endl;

    // Stop the task
    task.stop();

    // Waiting for thread to join
    threadObj.join();
    std::cout<<"Thread joined"<<std::endl;
    std::cout<<"Exiting main()"<<std::endl;

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/06-StopOrTerminateThread$ g++ UsingStoppableClass.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/06-StopOrTerminateThread$ ./a.out 
Task start
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
Asking task to stop
Task end
Thread joined
Exiting main()
*/
