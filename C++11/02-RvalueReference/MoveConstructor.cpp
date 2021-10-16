// 2 Objects of class Container are created at following step
// 1) Inside getContainer() function using Container class's default constructor 
// 2) While adding object in vector using Container class's copy constructor 
// How to solve this problem of resource and effort wastage due to temporary objects? Is there a way to move the 1st object instead of creating 2nd one and copying contents to it?     
// Answer is yes. This is where move semantics and rvalue references comes into picture.

#include <iostream>
#include <vector>

class Container
{
    private:
        int *m_data;

    public:
        Container()
        {
            // Allocate an array of 10 int on heap
            m_data = new int[10];
            std::cout<<"Constructor: Allocation 10 int"<<std::endl;
        }

        ~Container()
        {
            if(m_data)
            {
                delete []m_data;
                m_data = NULL;
            }   
        }

        // Copy Constructor 
        Container(const Container &obj)
        {
            // Allocate an array of 10 int on heap
            m_data = new int[10];
            for(int i = 0; i < 10; i++)
            {
                m_data[i] = obj.m_data[i];
            }
            std::cout<<"Copy Constructor: Allocation 10 int"<<std::endl;
        }

        // Assignment Operator
        Container& operator =(const Container &obj)
        {
            if(this != &obj)
            {
                m_data = new int[10];
                
                // copy the data from passed object
                for(int i = 0; i < 10; i++)
                {
                    m_data[i] = obj.m_data[i];
                }
                std::cout<<"Assignment operator: Allocation 10 int"<<std::endl;
            }
            return *this;
        }

        // Move Constructor 
        Container(Container &&obj)
        {
            // Just copy the pointer
            m_data = obj.m_data;

            // Set the passed object's member to NULL
            obj.m_data = NULL;

            std::cout<<"Move Constructor"<<std::endl;
        }
        
        // Move Assignment Operator
        Container& operator =(Container &&obj)
        {
            if(this != &obj)
            {
                // Just copy the pointer
                m_data = obj.m_data;

                // Set the passed object's member to NULL
                obj.m_data = NULL;

                std::cout<<"Move Assignment Operator"<<std::endl;
            }
            return *this;
        }
};

// Create object of Container and return
Container getContainer()
{
    Container obj;
    return obj;
}

int main()
{
    // Create a vector of Container Type
    std::vector<Container> vecOfContainers;

    // Move Constructor of class Container will be called because getContainer() returns rvalue and Container class has overloaded
    // version of Constructor that accepts rvalue in rvalue reference. Inside this Move constructor memory is just shifted. 

    // Add object retured by function into the vector 
    vecOfContainers.push_back(getContainer());

    // Move Assignment Operator was called instead of assignment operator and memory just got shifted
    Container obj;
    obj = getContainer(); // Move Assignment will be called 

    return 0;
}

/*Output:-)
Constructor: Allocation 10 int
Move Constructor
Constructor: Allocation 10 int
Constructor: Allocation 10 int
Move Assignment Operator
*/

