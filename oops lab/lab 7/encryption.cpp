#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encrypt(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "plain.txt";
    string outputFile = "encrypted.txt";
    int shift;

    cout << "Enter shift value: ";
    cin >> shift;

    encrypt(inputFile, outputFile, shift);
    cout << "Encryption complete! Encrypted content saved to " << outputFile << endl;

    return 0;
}
