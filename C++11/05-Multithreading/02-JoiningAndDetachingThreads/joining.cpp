#include <iostream>
#include <thread>
#include <vector>
#include <functional> // mem_fn
#include <algorithm>

class WorkerThread
{
    public:
        void operator()()
        {
            std::cout<<"Worker thread "<<std::this_thread::get_id()<<" is executing"<<std::endl;
        }
};

int main()
{
    std::vector<std::thread> threadList;

    for(int i = 0; i < 10; i++)
        threadList.push_back( std::thread( WorkerThread() ) );

    std::cout<<"Wait for all the worker thread to finish"<<std::endl;
    std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join)); // Use mem_fn to store and execute member function and member object
    std::cout<<"Exiting from main thread"<<std::endl;

    return 0;
}

/*Output:-)
Wait for all the worker thread to finish
Worker thread 140160439330560 is executing
Worker thread 140160447723264 is executing
Worker thread 140160456115968 is executing
Worker thread 140160464508672 is executing
Worker thread 140160430937856 is executing
Worker thread 140160422545152 is executing
Worker thread 140160405759744 is executing
Worker thread 140160414152448 is executing
Worker thread 140160472901376 is executing
Worker thread 140160481294080 is executing
Exiting from main thread
*/

