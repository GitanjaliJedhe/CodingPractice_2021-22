#include <stdio.h>

int x;

void AutoStorageClass()
{
    printf("\nDemonstrating auto class\n");
    
    auto int a = 89;
    
    printf("Value of variable 'a' declared as auto %d\n", a);
    printf("--------------------------------------------");
}

void RegisterStorageClass()
{
    printf("\nDemonstrating register class\n");
    
    register int r = 57;
    
    printf("Value of variable 'r' declared as register %d\n", r);
    printf("--------------------------------------------");
}

void ExternStorageClass()
{
    printf("\nDemonstrating extern class\n");
    
    extern int x;
    printf("Value of variable 'x' declared as extern %d\n", x);
    x = 39;    

    printf("Modified value of variable 'x' declared as extern %d\n", x);
    printf("--------------------------------------------");
}

void StaticStorageClass()
{
    printf("\nDemonstrating static class\n");
    int i;
    
    for(i = 0; i < 3; i++)
    {
        static int y; // static variables are initialize only once and exist till the termination of the program
        int p = 0; // non-static variable
    
        y++;
        p++;   

        printf("The value of 'sum' declared as static in %d iteration is %d\n", i, y);
        
        printf("The value of 'total' declared as non-static in %d iteration is %d\n", i, p);
    }

    printf("--------------------------------------------");
}

int main()
{
    printf("A program to demonstrate Storage Classes in C\n");

    AutoStorageClass();
    RegisterStorageClass();
    ExternStorageClass();
    StaticStorageClass();

    printf("\n\nStorage Classes demonstrated\n");
    return 0;
}

/*Output:-)
A program to demonstrate Storage Classes in C

Demonstrating auto class
Value of variable 'a' declared as auto 89
--------------------------------------------
Demonstrating register class
Value of variable 'r' declared as register 57
--------------------------------------------
Demonstrating extern class
Value of variable 'x' declared as extern 0
Modified value of variable 'x' declared as extern 39
--------------------------------------------
Demonstrating static class
The value of 'sum' declared as static in 0 iteration is 1
The value of 'total' declared as non-static in 0 iteration is 1
The value of 'sum' declared as static in 1 iteration is 2
The value of 'total' declared as non-static in 1 iteration is 1
The value of 'sum' declared as static in 2 iteration is 3
The value of 'total' declared as non-static in 2 iteration is 1
--------------------------------------------

Storage Classes demonstrated
*/ 
