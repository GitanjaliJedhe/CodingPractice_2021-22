// Namespace Aliasing
#include <iostream>

namespace name1
{
    namespace name2
    {
        namespace name3
        {
            int var = 10;
        }
    }
}

// Aliasing
namespace aliase = name1::name2::name3;

int main()
{
    std::cout<<aliase::var<<std::endl;
    return 0;
}

/*Output:
10
*/
