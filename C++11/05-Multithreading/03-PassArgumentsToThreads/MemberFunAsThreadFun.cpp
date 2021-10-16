#include <iostream>
#include <thread>

class Demo
{
    public:
        void fun(int x)
        {
            std::cout<<"Inside fun() x = "<<x<<std::endl;
        }
};

int main()
{
    Demo obj;
    int x = 10;
    std::thread threadObj(&Demo::fun, &obj, x);
    threadObj.join();
    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/03-PassArgumentsToThreads$ g++ MemberFunAsThreadFun.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/03-PassArgumentsToThreads$ ./a.out 
Inside fun() x = 10
*/
