#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    int id;
    string name;
    double salary;

public:
    Employee(int empId, const string& empName, double empSalary) {
        id = empId;
        name = empName;
        salary = empSalary;
    }

    virtual void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nSalary: $" << salary << endl;
    }
};

class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager(int empId, const string& empName, double empSalary, double mgrBonus)
        : Employee(empId, empName, empSalary) {
        bonus = mgrBonus;
    }

    void display() const override {
        Employee::display();
        cout << "Bonus: $" << bonus << endl;
    }
};

class TeamLeader : virtual public Employee {
protected:
    int number_of_team_members;

public:
    TeamLeader(int empId, const string& empName, double empSalary, int numMembers)
        : Employee(empId, empName, empSalary) {
        number_of_team_members = numMembers;
    }

    void display() const override {
        Employee::display();
        cout << "Number of Team Members: " << number_of_team_members << endl;
    }
};

class SeniorManager : public Manager, public TeamLeader {
public:
    SeniorManager(int empId, const string& empName, double empSalary, double mgrBonus, int numMembers)
        : Employee(empId, empName, empSalary), Manager(empId, empName, empSalary, mgrBonus), TeamLeader(empId, empName, empSalary, numMembers) {}

    void modifyAttributes(double newBonus, int newNumMembers) {
        bonus = newBonus;
        number_of_team_members = newNumMembers;
    }

    void display() const override {
        Employee::display();
        cout << "Bonus: $" << bonus << "\nNumber of Team Members: " << number_of_team_members << endl;
    }
};

int main() {
    SeniorManager sm(1, "John Doe", 100000, 15000, 10);
    cout << "Senior Manager Details:" << endl;
    sm.display();

    cout << "\nModifying bonus and number of team members..." << endl;
    sm.modifyAttributes(20000, 15);

    cout << "\nUpdated Senior Manager Details:" << endl;
    sm.display();

    return 0;
}
