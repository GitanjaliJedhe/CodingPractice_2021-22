#include <iostream>

class Complex
{
    private:
        double real;
        double imag;

    public:
        // Default constructor
        //Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
        explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
        {
        }
        
        // A method to compare two Complex numbers
        bool operator ==(Complex rhs)
        {
            return (real == rhs.real && imag == rhs.imag) ? true: false;
        }
        
};

int main()
{
    Complex comp(3.0, 0.0);
    
    //if(comp == 3.0)
    if(comp == (Complex)3.0)
    {
        std::cout<<"Same"<<std::endl;
    }
    else
    {
        std::cout<<"Not Same"<<std::endl;
    }

    return 0;
}

/*Output :-)
Same
*/

/*Output :-(
explicit.cpp: In function ‘int main()’:
explicit.cpp:28:13: error: no match for ‘operator==’ (operand types are ‘Complex’ and ‘double’)
28 |     if(comp == 3.0)
|        ~~~~ ^~ ~~~
|        |       |
|        Complex double
explicit.cpp:17:14: note: candidate: ‘bool Complex::operator==(Complex)’
17 |         bool operator ==(Complex rhs)
|              ^~~~~~~~
explicit.cpp:17:34: note:   no known conversion for argument 1 from ‘double’ to ‘Complex’
17 |         bool operator ==(Complex rhs)
|                          ~~~~~~~~^~~
*/

/*Output :-)
Same
*/

