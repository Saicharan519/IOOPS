// Complex Number Arithmetic
// Problem: Implement a class Complex to represent complex numbers and overload the arithmetic 
// operators (+, -, *, /) to perform operations between two complex numbers. Also, overload the << 
// operator to print the complex number in the form a + bi.
// Example:
// Complex c1(3, 4), c2(1, 2);
// Complex c3 = c1 + c2;
// cout << c3; // Output: 4 + 6

#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        double new_real = real * other.real - imag * other.imag;
        double new_imag = real * other.imag + imag * other.real;
        return Complex(new_real, new_imag);
    }

    // Overload / operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double new_real = (real * other.real + imag * other.imag) / denominator;
        double new_imag = (imag * other.real - real * other.imag) / denominator;
        return Complex(new_real, new_imag);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << endl;

    Complex c5 = c1 * c2;
    cout << "c1 * c2 = " << c5 << endl;

    Complex c6 = c1 / c2;
    cout << "c1 / c2 = " << c6 << endl;

    return 0;
}
