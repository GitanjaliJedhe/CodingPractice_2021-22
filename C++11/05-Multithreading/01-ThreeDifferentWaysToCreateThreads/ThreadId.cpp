#include <iostream>
#include <thread>

void thread_function()
{
    std::cout<<"Inside thread :: id = "<<std::this_thread::get_id()<<std::endl;
}

int main()
{
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);

    if(threadObj1.get_id() != threadObj2.get_id())
    {
        std::cout<<"Both threads have different ids"<<std::endl;
    }

    std::cout<<"Insided mainthread :: id of thread 1 = "<<threadObj1.get_id()<<std::endl;
    std::cout<<"Insided mainthread :: id of thread 2 = "<<threadObj2.get_id()<<std::endl;

    threadObj1.join();
    threadObj2.join();

    return 0;
}

/*Output:-)
Both threads have different ids
Insided mainthread :: id of thread 1 = 140089947965184
Insided mainthread :: id of thread 2 = 140089939572480
Inside thread :: id = 140089939572480
Inside thread :: id = 140089947965184
*/
