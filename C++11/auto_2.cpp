// C++ program to demonstrate that we can use auto to 
// save time when creating iterator

#include <iostream>
#include <set>

int main()
{
    std::set<std::string> st;
    
    st.insert({"geeks", "for", "geeks", "org"});    

    for(auto it = st.begin(); it != st.end(); it++)
    {
        std::cout<<(*it)<<" ";
    }

    return 0;
}

/*Output:-)
for geeks org
*/
