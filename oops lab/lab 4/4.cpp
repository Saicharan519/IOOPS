#include <iostream>
using namespace std;

// Helper function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator, denominator;

    // Simplify the fraction by dividing by the GCD of the numerator and denominator
    void simplify() {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    // Constructor
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        simplify();
    }

    // Overload + operator
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overload - operator
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overload * operator
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overload / operator
    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f1(3, 4), f2(5, 6);

    Fraction f3 = f1 + f2;
    cout << "f1 + f2 = " << f3 << endl;

    Fraction f4 = f1 - f2;
    cout << "f1 - f2 = " << f4 << endl;

    Fraction f5 = f1 * f2;
    cout << "f1 * f2 = " << f5 << endl;

    Fraction f6 = f1 / f2;
    cout << "f1 / f2 = " << f6 << endl;

    return 0;
}
