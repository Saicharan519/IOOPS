#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream sourceFile("source.txt");
    ofstream destinationFile("destination.txt");

    // Check if the source file opened successfully
    if (!sourceFile) {
        cerr << "Error: Could not open source file." << endl;
        return 1; // Exit with an error code if the file cannot be opened
    }

    // Check if the destination file opened successfully
    if (!destinationFile) {
        cerr << "Error: Could not open destination file." << endl;
        return 1; // Exit with an error code if the file cannot be opened
    }

    // Copy content from source to destination
    string line;
    while (getline(sourceFile, line)) {
        destinationFile << line << endl; // Write each line to the destination file
    }

    // Close both files
    sourceFile.close();
    destinationFile.close();

    cout << "Content successfully copied from source.txt to destination.txt" << endl;

    return 0;
}
