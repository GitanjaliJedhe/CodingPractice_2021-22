#include <iostream>

class Base
{
    public:
        virtual void fun()
        {
            std::cout<<"Base::fun"<<std::endl;
        }
};

class Derived : public Base
{
    public:
        virtual void fun() override final 
        {
            std::cout<<"Derived::fun"<<std::endl;
        }
};

/*
class Final : public Derived
{
    public:
        // function declared as 'final' cannot be overridden by Final::fun
        virtual void fun() override
        {
            std::cout<<"Final::fun"<<std::endl;
        }
};
*/


class A final
{
};

/*
class B : public A // Special identifier final adds the ability to prevent inheriting from  from classes
{
};
*/

int main()
{
    return 0;
}

/*Output before :-(
final.cpp:24:22: error: virtual function ‘virtual void Final::fun()’ overriding final function
24 |         virtual void fun() override
|                      ^~~
final.cpp:15:22: note: overridden function is ‘virtual void Derived::fun()’
15 |         virtual void fun() override final



final.cpp:37:7: error: cannot derive from ‘final’ base ‘A’ in derived type ‘B’
37 | class B : public A
|       ^
*/
