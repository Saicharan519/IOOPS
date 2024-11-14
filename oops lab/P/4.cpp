#include <fstream>
#include <iostream>
#include <string> // Include string library
using namespace std;

int main() {
    string data; // Change from char array to std::string

    // Open a file in write mode.
    ofstream outfile("afile.dat");
    if (!outfile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return 1; // Exit if the file couldn't be opened
    }

    cout << "Writing to the file" << endl;
    cout << "Enter your name: "; 
    getline(cin, data); // Use getline for name input

    // Write inputted data into the file.
    outfile << data << endl;

    cout << "Enter your age: "; 
    getline(cin, data); // Use getline for age input

    // Again write inputted data into the file.
    outfile << data << endl;

    // Close the opened file.
    outfile.close();

    // Open a file in read mode.
    ifstream infile("afile.dat");
    if (!infile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Exit if the file couldn't be opened
    }

    cout << "Reading from the file" << endl; 
    getline(infile, data); // Read name
    cout << data << endl;

    // Again read the data from the file and display it.
    getline(infile, data); // Read age
    cout << data << endl; 

    // Close the opened file.
    infile.close();

    return 0;
}
