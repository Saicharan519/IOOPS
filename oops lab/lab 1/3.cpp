#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string empName, int empID, double empSalary) {
        name = empName;
        employeeID = empID;
        salary = empSalary;
    }

    void setSalaryBasedOnPerformance(char performanceGrade) {
        double bonusPercentage;

        switch (performanceGrade) {
            case 'A':
                bonusPercentage = 0.20;
                break;
            case 'B':
                bonusPercentage = 0.10;
                break;
            case 'C':
                bonusPercentage = 0.05;
                break;
            case 'D':
                bonusPercentage = 0.02;
                break;
            default:
                bonusPercentage = 0.0;
                break;
        }

        salary += salary * bonusPercentage;
    }

    void displayEmployeeDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", 12345, 50000);

    cout << "Initial Employee Details:" << endl;
    emp.displayEmployeeDetails();

    char performanceGrade = 'A';
    emp.setSalaryBasedOnPerformance(performanceGrade);

    cout << "\nUpdated Employee Details after performance evaluation:" << endl;
    emp.displayEmployeeDetails();

    return 0;
}
