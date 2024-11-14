#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};

    try {
        int index;
        cout << "Enter an index to access an element (0 to " << size - 1 << "): ";
        cin >> index;

        // Check for out of bounds access
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        cout << "Element at index " << index << ": " << arr[index] << endl;

    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
