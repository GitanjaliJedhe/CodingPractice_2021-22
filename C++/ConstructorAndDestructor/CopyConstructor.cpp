/*When is copy constructor called?
1) When an object of the class is retured by value
2) When object of the class is passed by value as an argument
3) When an object is constructed based on another object of the class
4) When the compiler generates a temporary object
*/

#include <iostream>

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
    
        // Copy Constructor
        Point(const Point &p1)
        {
            x = p1.x;
            y = p1.y;
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
    Point p1(25, 25);
    
    Point p2 = p1; // Copy Constructor is called here    

    std::cout<<"p1.x= "<<p1.getX()<<" , p1.y = "<<p1.getY()<<std::endl;
    std::cout<<"p2.x= "<<p2.getX()<<" , p2.y = "<<p2.getY()<<std::endl;

    return 0;
}

/*Output:-)
p1.x= 25 , p1.y = 25
p2.x= 25 , p2.y = 25
*/
