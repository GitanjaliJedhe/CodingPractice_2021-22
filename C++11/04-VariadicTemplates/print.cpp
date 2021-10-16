// variadic templates works as follow:
// print(1, 2, 3.14, "Pass me any", " number of arguments ", "I will print\n");
// std::cout<<1<<std::endl;
// print(2, 3.14, "Pass me any", " number of arguments ", "I will print\n");
// std::cout<<2<<std::endl;
// print(3.14, "Pass me any", " number of arguments ", "I will print\n");
// std::cout<<3.14<<std::endl;
// print("Pass me any", " number of arguments ", "I will print\n");
// std::cout<<"Pass me any"<<std::endl;
// print(" number of arguments ", "I will print\n");
// std::cout<<"number of arguments"<<std::endl;
// print"I will print\n");
// std::cout<<"I will print\n"<<std::endl;
// print()

#include <iostream>

// To handle base case of below recursive variadic function template
void print()
{
    std::cout<<"I am empty function and I am called at last"<<std::endl;
}

// Variadic function template that takes variable number of arguments and prints all of them 
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    std::cout<<var1<<std::endl;
    print(var2...);
}

int main()
{
    print(1, 2, 3.14, "Pass me any", " number of arguments ", "I will print\n");
    return 0;
}

/*Output:-)
1
2
3.14
Pass me any
number of arguments
I will print
*/
