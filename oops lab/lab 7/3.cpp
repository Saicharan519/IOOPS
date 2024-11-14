#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    string toReplace, replaceWith;

    // Get user input for the words to replace
    cout << "Enter the word to replace: ";
    getline(cin, toReplace);
    cout << "Enter the replacement word: ";
    getline(cin, replaceWith);

    // Open the input file
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Open the output file
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    string line;
    // Read each line from the input file
    while (getline(inFile, line)) {
        size_t pos = 0;
        // Replace all occurrences of the word
        while ((pos = line.find(toReplace, pos)) != string::npos) {
            line.replace(pos, toReplace.length(), replaceWith);
            pos += replaceWith.length(); // Move past the replaced word
        }
        outFile << line << endl; // Write the modified line to the output file
    }

    // Close the files
    inFile.close();
    outFile.close();

    cout << "Text replacement complete! Modified content saved to " << outputFile << endl;

    return 0;
}
