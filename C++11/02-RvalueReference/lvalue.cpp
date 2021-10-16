// lvalue is anything whose address is accessible. It means we can take address of lvalue using & operator.
// It means we cannot take address of rvalue
// Eg. int c = (a+b); // c is lvalue and (a+b) is rvalue

// rvalue of builtin data type is Immutable
// (x+7) = 7 // Compile Error - Can not Modify rvalue

// rvalue of User Defined data type is not Immutable
#include <iostream>
class Person
{
    private:
        int m_age;
    public:
        Person()
        {
            m_age = 10;
        }

        void incrementAge()
        {
            m_age = m_age + 1;
        }
};

Person getPerson()
{
    return Person();
}

int main()
{
    //Person *ptrPerson = &getPerson();
    getPerson().incrementAge(); // Here we have modified a rvalue of Person class type with its member function in the same expression
    return 0;
}

// rvalue References 
// rvalue references can do what lvalue references fails to do i.e a rvalue reference can refer to rvalues.
// To declare a rvalue reference, we need to specify two & operator i.e &&
// int && rvalueRef = (x+1); // rvalueRef is rvalue reference
