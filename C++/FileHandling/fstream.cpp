#include <iostream>
#include <fstream> // For ifstream, ofstream, fstream classes

int main()
{
    std::fstream fio;

    std::string line;

    fio.open("sample.txt", std::ios::trunc | std::ios::out | std::ios::in);

    while(fio)
    {
        getline(std::cin, line); // Read a line from standard input

        if(line == "-1")
        {
            break;
        }
        
        fio<<line<<std::endl;
    }

    // read pointer at beginning of file 
    fio.seekg(0, std::ios::beg); // seekg(offset, dir)

    while(fio)
    {
        getline(fio, line);
        std::cout<<line<<std::endl;
    }

    fio.close();

    return 0;
}

/*Output:-)
Gitanjali Dilip Jedhe
Siemens Technology and Services Pvt. Ltd.
-1
Gitanjali Dilip Jedhe
Siemens Technology and Services Pvt. Ltd.

*/
