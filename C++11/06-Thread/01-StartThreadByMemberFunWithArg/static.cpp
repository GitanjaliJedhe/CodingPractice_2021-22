#include <iostream>
#include <thread>

class Task
{
    public:
        static void execute(std::string command)   
        {
            for(int i = 0; i < 5; i++)
            {   
                std::cout<<command<<" :: "<<i<<std::endl;
            }
        }
};

int main()
{
    std::string cmd = "sample task";   

    // As static functions are not associated with any object of class. So, we can directly pass static member function of class as thread function without passing any pointer to object
    std::thread threadObj(&Task::execute, cmd);
    
    threadObj.join();

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/01-StartThreadByMemberFunWithArg$ g++ static.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/06-Thread/01-StartThreadByMemberFunWithArg$ ./a.out 
sample task :: 0
sample task :: 1
sample task :: 2
sample task :: 3
sample task :: 4
*/

