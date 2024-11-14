#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream mergedFile("merged.txt");

    if (!file1) {
        cerr << "Error: Could not open file1.txt." << endl;
        return 1;
    }

    if (!file2) {
        cerr << "Error: Could not open file2.txt." << endl;
        return 1;
    }

    if (!mergedFile) {
        cerr << "Error: Could not open merged.txt." << endl;
        return 1;
    }

    string line;
    while (getline(file1, line)) {
        mergedFile << line << endl;
    }

    while (getline(file2, line)) {
        mergedFile << line << endl;
    }

    file1.close();
    file2.close();
    mergedFile.close();

    cout << "Content successfully merged into merged.txt." << endl;

    return 0;
}
