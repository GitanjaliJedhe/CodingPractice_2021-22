// Using std::ref()

#include <iostream>
#include <thread>

void thread_function(const int &x)
{
    int& y =  const_cast<int &>(x);
    y++;
    std::cout<<"Inside thread x = "<<x<<std::endl;
}

int main()
{
    int i = 9;
    std::cout<<"Inside mainthread : Before Thread Start x = "<<i<<std::endl;
    std::thread threadObj(thread_function, std::ref(i));
    threadObj.join();
    std::cout<<"Inside mainthread : After Thread Join x = "<<i<<std::endl;
    return 0;
}

/*Output:-(
Inside mainthread : Before Thread Start x = 9
Inside thread x = 10
Inside mainthread : After Thread Join x = 9
*/

/*Output:-)
Inside mainthread : Before Thread Start x = 9
Inside thread x = 10
Inside mainthread : After Thread Join x = 10
*/
