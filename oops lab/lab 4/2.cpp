// Matrix Operations
// Problem: Create a class Matrix to represent a 2x2 matrix. Overload the + and * operators to allow 
// matrix addition and multiplication. Implement operator overloading to make matrix operations as 
// intuitive as possible.
// Example:
// Matrix m1({{1, 2}, {3, 4}});
// Matrix m2({{2, 0}, {1, 2}});
// Matrix m3 = m1 + m2;
// Matrix m4 = m1 * m2;

#include <iostream>
using namespace std;

class Matrix {
private:
    int data[2][2];

public:
    // Constructor to initialize matrix elements
    Matrix(int arr[2][2]) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                data[i][j] = arr[i][j];
    }

    // Overload + operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        int result[2][2];
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result[i][j] = data[i][j] + other.data[i][j];
        return Matrix(result);
    }

    // Overload * operator for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        int result[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                out << m.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    int arr1[2][2] = {{1, 2}, {3, 4}};
    int arr2[2][2] = {{2, 0}, {1, 2}};

    Matrix m1(arr1);
    Matrix m2(arr2);

    Matrix m3 = m1 + m2;
    cout << "m1 + m2 = " << endl << m3;

    Matrix m4 = m1 * m2;
    cout << "m1 * m2 = " << endl << m4;

    return 0;
}
