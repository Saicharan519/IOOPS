#include <iostream>
#include <string>  

using namespace std;

class Student {
    string name;  
    int studentClass;  
    int roll;
    int marks;

public:
    void getdata() {
        cout << "Enter the name, class, roll number, marks (from 0 to 100) of the student:" << endl;
        cin >> name >> studentClass >> roll >> marks;
    }

    void displaydata() {
        cout << "Student details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Roll number: " << roll << endl;
        cout << "Marks: " << marks << endl;

        if (marks == 100) {
            cout << "Grade: A+" << endl;
        } else if (marks >= 80 && marks < 100) {
            cout << "Grade: A" << endl;
        } else if (marks >= 50 && marks < 80) {
            cout << "Grade: B" << endl;
        } else if (marks >= 30 && marks < 50) {
            cout << "Grade: C" << endl;
        } else if (marks >= 10 && marks < 30) {
            cout << "Grade: D" << endl;
        } else if (marks >= 0 && marks < 10) {
            cout << "Grade: F" << endl;
        } else {
            cout << "Invalid marks entered!" << endl;
        }
    }
};

int main() {
    Student s;
    s.getdata();
    s.displaydata();
    return 0;
}
