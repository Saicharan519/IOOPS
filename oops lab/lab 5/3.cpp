#include <iostream>
#include <iomanip>
using namespace std;

class Currency {
private:
    double amount_usd;        // Amount in USD
    static constexpr double exchange_rate = 0.85; // Exchange rate from USD to EUR

public:
    // Constructor
    Currency(double usd) : amount_usd(usd) {}

    // Helper functions to convert between USD and EUR
    double toEUR() const {
        return amount_usd * exchange_rate;
    }

    double toUSD() const {
        return amount_usd;
    }

    // Overload + operator to add two Currency objects
    Currency operator+(const Currency& other) const {
        return Currency(amount_usd + other.amount_usd);
    }

    // Overload - operator to subtract two Currency objects
    Currency operator-(const Currency& other) const {
        return Currency(amount_usd - other.amount_usd);
    }

    // Overload * operator to multiply currency by a scalar
    Currency operator*(double multiplier) const {
        return Currency(amount_usd * multiplier);
    }

    // Overload / operator to divide currency by a scalar
    Currency operator/(double divisor) const {
        if (divisor == 0) {
            cerr << "Error: Division by zero!" << endl;
            return *this;
        }
        return Currency(amount_usd / divisor);
    }

    // Overload << operator to display amount in both currencies
    friend ostream& operator<<(ostream& out, const Currency& c) {
        out << fixed << setprecision(2);
        out << "$" << c.amount_usd << " (USD), " << c.toEUR() << " (EUR)";
        return out;
    }
};

int main() {
    Currency c1(100); // $100
    Currency c2(50);  // $50

    Currency c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    Currency c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << endl;

    Currency c5 = c1 * 2;
    cout << "c1 * 2 = " << c5 << endl;

    Currency c6 = c1 / 4;
    cout << "c1 / 4 = " << c6 << endl;

    return 0;
}
