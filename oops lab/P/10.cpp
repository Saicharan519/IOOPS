// PROGRAM:
// inf.seekg(14, std::ios::cur); // move forward 14 bytes
// inf.seekg(-18, std::ios::cur); // move backwards 18 bytes
// inf.seekg(22, std::ios::beg); // move to 22nd byte in file
// inf.seekg(24); // move to 24th byte in file
// inf.seekg(-28, std::ios::end); // move to the 28th byte before end of the file
// inf.seekg(0, std::ios::beg); // move to beginning of file
// inf.seekg(0, std::ios::end); // move to end of file

#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    std::string strData;

    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it, moving to line 2
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(8, std::ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(-14, std::ios::end); // move 14 bytes before end of file
    // Get rest of the line and print it
    std::getline(inf, strData); // undefined behavior
    std::cout << strData << '\n';

    return 0;
}
