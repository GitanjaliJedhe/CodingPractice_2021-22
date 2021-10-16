#include <iostream>
#include <thread>
#include <vector>

class Wallet
{
    private:
        int m_money;
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
            for(int i = 0; i < money; i++)
            {
                m_money++;
            }
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

/*Output:-(
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/04-DataSharingAndRaceConditions$ g++ RaceCondition.cpp -lpthread
gitanjali@gitanjali-VirtualBox:~/Documents/GitHub/practice_program/C++11/Multithreading/04-DataSharingAndRaceConditions$ ./a.out 
Error at count = 122 Money in Wallet = 4000
*/

