// 2 Objects of class Container are created at following step
// 1) Inside getContainer() function using Container class's default constructor 
// 2) While adding object in vector using Container class's copy constructor 
// How to solve this problem of resource and effort wastage due to temporary objects? Is there a way to move the 1st object instead of creating 2nd one and copying contents to it?     

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

    // Add object retured by function into the vector 
    vecOfContainers.push_back(getContainer());

    return 0;
}

/*Output:-)
Constructor: Allocation 10 int
Copy Constructor: Allocation 10 int
*/

