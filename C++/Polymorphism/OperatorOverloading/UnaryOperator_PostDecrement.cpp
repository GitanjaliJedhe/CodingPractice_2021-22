#include <iostream>

using namespace std;

class Check
{
    private:
        int i;
    public:
        Check() : i(3) { }
        
        Check operator --()
        {
            Check temp;
            temp.i = --i;
            return temp;
        }

        Check operator --(int) // int inside bracket indicates post decrement
        {
            Check temp;
            temp.i = i--;
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

    obj2 = --obj1;
    obj1.Display();
    obj2.Display();

    obj2 = obj1--;
    obj1.Display();
    obj2.Display();    

    return 0;
}

/*Output:-)
*/
