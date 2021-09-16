#include <iostream>
#include <fstream> // For ifstream, ofstream and fstream

int main()
{
    std::ofstream fout;
    std::string line;
    
    fout.open("sample.txt"); // By default ios::out mode
    
    while(fout)
    {
        getline(std::cin, line); // Read a line from stdin
        
        // Press -1 to exit
        if(line == "-1")
            break;

        fout<<line<<std::endl;
    }

    fout.close();

    std::ifstream fin;
    
    fin.open("sample.txt"); // By default open mode ios::in

    // Execute a loop until EOF
    while(fin)
    {
        getline(fin, line);
        std::cout<<line<<std::endl;
    }

    fin.close();

    return 0;
}

/*Output:-)
Gitanjali Dilip Jedhe    
-1
Gitanjali Dilip Jedhe

*/
