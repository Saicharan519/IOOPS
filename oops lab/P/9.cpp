Reading a file
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    string str;
    ifstream in("example.txt");
    in >> str;
    cout << str;
    return 0;
}
