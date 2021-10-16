#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Wallet
{
    private:
        int m_money;
        std::mutex mutex;

    public:
        Wallet() : m_money(0)
        {
        }
        
        int getMoney()
        {
            return m_money;
        }
        
        void addMoney(int money)
        {
            std::lock_guard<std::mutex> lockGuard(mutex);
            // In constructor it locks the mutex

            for(int i = 0; i < money; i++)
            {
                // If some exception occurs at this point
                // then destructor of lockGuard will be called
                // due to stack unwinding.
                m_money++;
            }

            // Once function exits, then destructor of lockGuard will be called.
            // In destructor it unlocks the mutex.
        }
        
};

int testMultithreadedWallet()
{
    Wallet walletObject;

    std::vector<std::thread> threadList;
    for(int i = 0; i < 5; i++)
    {
        threadList.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }

    for(int i = 0; i < threadList.size(); i++)
    {
        threadList.at(i).join();
    }
    
    return walletObject.getMoney();
}

int main()
{
    int retVal;

    for(int i = 0; i < 1000; i++)
    {
        if((retVal = testMultithreadedWallet()) != 5000)
        {
            std::cout<<"Error at count = "<<i<<" Money in Wallet = "<<retVal<<std::endl;
        }
    }

    return 0;
}

/*Output:-)
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/05-MutexToFixRaceConditions$ g++ lock_guard.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/05-MutexToFixRaceConditions$ ./a.out 
*/

