#include <iostream>
#include <cstring>

using namespace std;

class String
{
    private:
        char *s;
        int size;

    public:
        String(const char *str = NULL); // Constructor
        ~String() { delete [] s; }; // Destructor
        String(const String &); // Copy Constructor

        void print() { cout << s << endl; }
        void change(const char *); 
};


String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::String(const String &old_str)
{
    size = old_str.size;
    s = new char[size+1];
    strcpy(s, old_str.s);
}

void String::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

int main()
{
    String str1("Gitanjali Jedhe");
    String str2 = str1;

    str1.print();
    str2.print();

    str2.change("Gitanjali Dilip Jedhe");
     
    str1.print();
    str2.print();

    return 0;
}
