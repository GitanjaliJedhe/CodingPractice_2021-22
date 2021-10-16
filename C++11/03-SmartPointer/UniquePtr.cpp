#include <iostream>
#include <memory>

class Rectangle
{
    private:
        int length;
        int breadth;

    public:
        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return length * breadth;
        }
};

int main()
{
    std::unique_ptr<Rectangle> P1(new Rectangle(20, 5));
    std::cout<< P1->area() <<std::endl;
   
    std::unique_ptr<Rectangle> P2; 
    P2 = move(P1);

    std::cout<< P2->area() <<std::endl;
    //std::cout<< P1->area() <<std::endl;

    return 0;
}

/*Output:-(
100
100
Segmentation fault (core dumped)
*/

/*Output:-)
100
100
*/
