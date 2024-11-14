#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decrypt(const string& inputFile, const string& outputFile, int shift) {
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
            ch = (ch - base - shift + 26) % 26 + base;
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "encrypted.txt";
    string outputFile = "decrypted.txt";
    int shift;

    cout << "Enter shift value: ";
    cin >> shift;

    decrypt(inputFile, outputFile, shift);
    cout << "Decryption complete! Decrypted content saved to " << outputFile << endl;

    return 0;
}
