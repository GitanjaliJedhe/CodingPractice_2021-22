#include <iostream>

class Test
{
    public:
        void fun(char *);
        void fun(int);
};

void fun(char *pc)
{
    std::cout<<"Fun accepting char *"<<std::endl;
}

void fun(int i)
{
    std::cout<<"Fun accepting int"<<std::endl;
}

int main()
{
    fun(nullptr); // calls fun(char *), not fun(int)

    return 0;
}
