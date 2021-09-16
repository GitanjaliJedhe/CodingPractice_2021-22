#include <iostream>

class Test
{
    private:
        int num1;
        int num2;

    public:
        // Default Constructor
        Test()
        {
            num1 = 10;
            num2 = 20;
            
        }

        void Display()
        {
            std::cout<<"Num1 = "<<num1<<" Num2 = "<<num2<<std::endl;
        }
};

int main()
{
    // Default constructor called automatically when the object is created
    Test obj;
    
    obj.Display();

    return 0;
}

/*Output:-)
Num1 = 10 Num2 = 20
*/
