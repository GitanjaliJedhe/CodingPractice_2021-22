#include <iostream>
#include <string>
#include <thread>

void thread_function(int i, std::string str)
{
    std::cout<<"Passed Number "<<i<<std::endl;
    std::cout<<"Passed String "<<str<<std::endl;
}

int main()
{
    int i = 1;
    std::string str = "Gitanjali"; 
    std::thread threadObj(thread_function, i, str);

    threadObj.join();

    return 0;
}

/*Output:-)
g++ SimpleArguments.cpp -lpthread
./a.out
Passed Number 1
Passed String Gitanjali
*/
