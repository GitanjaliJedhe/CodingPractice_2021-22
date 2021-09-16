#include <iostream>

class Sample
{
    public:
        Sample()
        {
            std::cout<<"Sample::Constructor"<<std::endl;
        }
        ~Sample()
        {
            std::cout<<"Sample::Destructor"<<std::endl;
        }
};

int main()
{
    Sample *ptr = new Sample();
    delete ptr;

    return 0;
}

/*Output:-)
Sample::Constructor
Sample::Destructor
*/
