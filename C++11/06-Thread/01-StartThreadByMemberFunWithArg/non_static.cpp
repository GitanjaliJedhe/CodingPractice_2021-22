#include <iostream>
#include <thread>

class Task
{
    public:
        void execute(std::string command)   
        {
            for(int i = 0; i < 5; i++)
            {   
                std::cout<<command<<" :: "<<i<<std::endl;
            }
        }
};

int main()
{
    Task *taskPtr = new Task();
    std::string cmd = "sample task";   

    // create thread using member function
    // std::thread constructor we passed 3 arguments
    // 1) Pointer to member function i.e execute() of class Task
    //    When std::thread will internally create a new thread, it will use this passed member function as thread function. But to call member function, we need object
    // 2) Pointer to object of class Task
    //    Because every non static member function, first argument is always pointer to object of its own class. So, thread class will pass this pointer as first argument while calling passed member function
    // 3) String value
    //    This will be passed as second argument to member function 
    std::thread threadObj(&Task::execute, taskPtr, cmd);
    
    threadObj.join();

    delete taskPtr;

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/01-StartThreadByMemberFunWithArg$ g++ non_static.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/01-StartThreadByMemberFunWithArg$ ./a.out
sample task :: 0
sample task :: 1
sample task :: 2
sample task :: 3
sample task :: 4
*/

