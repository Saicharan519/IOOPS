#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string brand;
    double rental_rate_per_day;

public:
    Vehicle(int id, const string& br, double rate) {
        vehicleID = id;
        brand = br;
        rental_rate_per_day = rate;
    }

    virtual void display() const {
        cout << "Vehicle ID: " << vehicleID << "\nBrand: " << brand << "\nRental Rate per Day: $" << rental_rate_per_day << endl;
    }
};

class Car : virtual public Vehicle {
protected:
    int number_of_seats;
    bool has_air_conditioning;

public:
    Car(int id, const string& br, double rate, int seats, bool air_cond) : Vehicle(id, br, rate) {
        number_of_seats = seats;
        has_air_conditioning = air_cond;
    }

    void display() const override {
        Vehicle::display();
        cout << "Number of Seats: " << number_of_seats << "\nAir Conditioning: " << (has_air_conditioning ? "Yes" : "No") << endl;
    }
};

class Truck : virtual public Vehicle {
protected:
    double cargo_capacity;
    int number_of_wheels;

public:
    Truck(int id, const string& br, double rate, double capacity, int wheels) : Vehicle(id, br, rate) {
        cargo_capacity = capacity;
        number_of_wheels = wheels;
    }

    void display() const override {
        Vehicle::display();
        cout << "Cargo Capacity: " << cargo_capacity << " tons\nNumber of Wheels: " << number_of_wheels << endl;
    }
};

class PickupTruck : public Car, public Truck {
public:
    PickupTruck(int id, const string& br, double rate, int seats, bool air_cond, double capacity, int wheels)
        : Vehicle(id, br, rate), Car(id, br, rate, seats, air_cond), Truck(id, br, rate, capacity, wheels) {}

    void display() const override {
        Vehicle::display();
        cout << "Number of Seats: " << number_of_seats << "\nAir Conditioning: " << (has_air_conditioning ? "Yes" : "No") << endl;
        cout << "Cargo Capacity: " << cargo_capacity << " tons\nNumber of Wheels: " << number_of_wheels << endl;
    }
};

int main() {
    PickupTruck pt(101, "Ford", 150, 4, true, 2.5, 4);
    cout << "Pickup Truck Details:" << endl;
    pt.display();

    return 0;
}
