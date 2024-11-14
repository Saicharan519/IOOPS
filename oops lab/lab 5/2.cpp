#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

    // Helper function to normalize time (e.g., convert 75 minutes to 1 hour and 15 minutes)
    void normalize() {
        hours += minutes / 60;
        minutes %= 60;
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        hours = (hours + 24) % 24; // Wrap around 24 hours
    }

public:
    // Constructor
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        normalize();
    }

    // Overload + operator to add two Time objects
    Time operator+(const Time& other) const {
        int total_hours = hours + other.hours;
        int total_minutes = minutes + other.minutes;
        return Time(total_hours, total_minutes);
    }

    // Overload - operator to subtract two Time objects
    Time operator-(const Time& other) const {
        int total_hours = hours - other.hours;
        int total_minutes = minutes - other.minutes;
        return Time(total_hours, total_minutes);
    }

    // Overload << operator to print time in HH:MM format
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << setw(2) << setfill('0') << t.hours << ":"
            << setw(2) << setfill('0') << t.minutes;
        return out;
    }
};

int main() {
    Time t1(22, 30); // 22:30
    Time t2(1, 40);  // 01:40

    Time t3 = t1 + t2;
    cout << "t1 + t2 = " << t3 << endl; // Expected output: 00:10

    Time t4 = t1 - t2;
    cout << "t1 - t2 = " << t4 << endl; // Expected output: 20:50

    return 0;
}
