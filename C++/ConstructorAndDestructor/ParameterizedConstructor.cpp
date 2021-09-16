#include <iostream>

using namespace std;

class Point
{
    private:
        int x, y;

    public:
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }
};

int main()
{
    Point p1(15, 15);

    cout<<"p1.x = "<<p1.getX()<<" , p1.y = "<<p1.getY()<<endl;

    return 0;
}

/*Output:-)
p1.x = 15 , p1.y = 15
*/
