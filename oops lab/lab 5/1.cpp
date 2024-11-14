#include <iostream>
using namespace std;

class Polynomial {
private:
    int* coefficients;
    int degree;

public:
    // Constructor to initialize the polynomial with given degree and coefficients
    Polynomial(int deg, int coeffs[]) : degree(deg) {
        coefficients = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    // Copy constructor for deep copy
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    // Destructor to free allocated memory
    ~Polynomial() {
        delete[] coefficients;
    }

    // Overload + operator for polynomial addition
    Polynomial operator+(const Polynomial& other) const {
        int max_degree = max(degree, other.degree);
        int result_coeffs[max_degree + 1] = {0};

        for (int i = 0; i <= max_degree; ++i) {
            if (i <= degree) result_coeffs[i] += coefficients[i];
            if (i <= other.degree) result_coeffs[i] += other.coefficients[i];
        }

        return Polynomial(max_degree, result_coeffs);
    }

    // Overload - operator for polynomial subtraction
    Polynomial operator-(const Polynomial& other) const {
        int max_degree = max(degree, other.degree);
        int result_coeffs[max_degree + 1] = {0};

        for (int i = 0; i <= max_degree; ++i) {
            if (i <= degree) result_coeffs[i] += coefficients[i];
            if (i <= other.degree) result_coeffs[i] -= other.coefficients[i];
        }

        return Polynomial(max_degree, result_coeffs);
    }

    // Overload * operator for polynomial multiplication
    Polynomial operator*(const Polynomial& other) const {
        int result_degree = degree + other.degree;
        int result_coeffs[result_degree + 1] = {0};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result_degree, result_coeffs);
    }

    // Overload << operator to print polynomial in standard form
    friend ostream& operator<<(ostream& out, const Polynomial& p) {
        bool isFirst = true;
        for (int i = p.degree; i >= 0; --i) {
            int coeff = p.coefficients[i];
            if (coeff != 0) {
                if (!isFirst && coeff > 0) out << " + ";
                if (coeff < 0) out << " - ";
                if (abs(coeff) != 1 || i == 0) out << abs(coeff);
                if (i > 0) out << "x";
                if (i > 1) out << "^" << i;
                isFirst = false;
            }
        }
        if (isFirst) out << "0";
        return out;
    }
};

int main() {
    int coeffs1[] = {1, 2, 3}; // Represents 3x^2 + 2x + 1
    int coeffs2[] = {2, 1};    // Represents x + 2

    Polynomial p1(2, coeffs1);
    Polynomial p2(1, coeffs2);

    Polynomial p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;

    Polynomial p4 = p1 - p2;
    cout << "p1 - p2 = " << p4 << endl;

    Polynomial p5 = p1 * p2;
    cout << "p1 * p2 = " << p5 << endl;

    return 0;
}
