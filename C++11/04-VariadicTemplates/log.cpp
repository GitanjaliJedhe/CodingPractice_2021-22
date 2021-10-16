#include <iostream>

// base case
void log()
{
}

/*Variadic Template Function that accepts variable number of arguments
* of any type. 
*/
template<typename T, typename... Args>
void log(T first, Args... args)
{
    // Print the first element
    std::cout<<first<<" , ";
    
    // Forward the remaining arguments
    log(args...);
}

int main()
{
    log(2, 3.4, "Gitanjali Jedhe");
    return 0;
}

/*Output:-)
2 , 3.4 , Gitanjali Jedhe , 
*/
