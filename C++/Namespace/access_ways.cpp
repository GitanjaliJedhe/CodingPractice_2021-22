// Access namespace 
// 1) Normal way
// 2) "using" directive
#include <iostream>

using namespace std;

namespace geek 
{
    int val = 300;   
}

namespace smart
{
    int val = 10;
}

using namespace smart;

int main()
{
    cout<<geek::val<<endl;
    cout<<val<<endl;
    return 0;
}

/*Output:
300
10
*/

