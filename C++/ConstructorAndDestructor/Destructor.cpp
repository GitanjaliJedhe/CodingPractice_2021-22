#include <iostream>
#include <cstring>

class String
{
    private:
        char *s;
        int size;

    public:
        String(char *); // Constructor
        ~String(); // Destructor
};

String::String(char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::~String()
{
    delete [] s;
}

int main()
{
    return 0;
}
