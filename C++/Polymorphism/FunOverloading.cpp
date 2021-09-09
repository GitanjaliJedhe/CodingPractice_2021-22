#include <iostream>

class Arithmetic
{
    public:
        int addition(int, int);
        int addition(int, int, int);
};

int Arithmetic::addition(int no1, int no2)
{
    return no1 + no2;
}


int Arithmetic::addition(int no1, int no2, int no3)
{
    return no1 + no2 + no3;
}

int main()
{
    int num1 = 400, num2 = 573, num3 = 876;
    Arithmetic obj;

    std::cout<<"Addition of Two Integers "<<obj.addition(num1, num2)<<std::endl;

    std::cout<<"Addition of Three Integers "<<obj.addition(num1, num2, num3)<<std::endl;

    return 0;
}

/*Output:-)
Addition of Two Integers 973
Addition of Three Integers 1849
*/
