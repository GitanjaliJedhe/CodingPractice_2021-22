#include <iostream>

using namespace std;

class Check
{
    private:
        int i;
    public:
        Check() : i(0) { }
        
        Check operator ++()
        {
            Check temp;
            temp.i = ++i;
            return temp;
        }

        Check operator ++(int) // int inside bracket indicates post increment
        {
            Check temp;
            temp.i = i++;
            return temp;
        }

        void Display()
        {
            cout<<"i = "<<i<<endl;
        }
};

int main()
{
    Check obj1, obj2;

    obj1.Display();
    obj2.Display();

    obj2 = ++obj1;
    obj1.Display();
    obj2.Display();

    obj2 = obj1++;
    obj1.Display();
    obj2.Display();    

    return 0;
}

/*Output:-)
i = 0
i = 0
i = 1
i = 1
i = 2
i = 1
*/
