#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;

public:
    Student() {
        name = "";
        rollNumber = 0;
        marks = 0.0;
    }

    Student(string stuName, int stuRollNumber, double stuMarks) {
        name = stuName;
        rollNumber = stuRollNumber;
        marks = stuMarks;
    }

    void displayStudentDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student student1;
    cout << "Student 1 Details (Using Default Constructor):" << endl;
    student1.displayStudentDetails();

    Student student2("Alice Smith", 101, 89.5);
    cout << "\nStudent 2 Details (Using Parameterized Constructor):" << endl;
    student2.displayStudentDetails();

    return 0;
}
