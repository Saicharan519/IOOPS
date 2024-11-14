#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isspace
using namespace std;

int main() {
    ifstream file("document.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1; // Exit the program if the file cannot be opened
    }

    string word;
    int wordCount = 0;
    int charCount = 0;

    while (file >> word) {
        wordCount++; // Increment word count for each word read
        charCount += word.length(); // Add the length of the word to character count
    }

    // To count the characters, we will also consider the spaces and newlines
    file.clear(); // Clear EOF flag
    file.seekg(0, ios::beg); // Go back to the start of the file

    char c;
    while (file.get(c)) {
        if (!isspace(c)) { // Count only non-whitespace characters
            charCount++;
        }
    }

    file.close(); // Close the file

    cout << "Total number of words: " << wordCount << endl;
    cout << "Total number of characters (excluding whitespace): " << charCount << endl;

    return 0;
}
