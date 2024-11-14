#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(const string& pname, int page, const string& paddress) {
        name = pname;
        age = page;
        address = paddress;
    }

    virtual void display() const {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << endl;
    }
};

class Student : virtual public Person {
protected:
    int studentID;
    double GPA;

public:
    Student(const string& pname, int page, const string& paddress, int sid, double gpa) 
        : Person(pname, page, paddress) {
        studentID = sid;
        GPA = gpa;
    }

    void display() const override {
        Person::display();
        cout << "Student ID: " << studentID << "\nGPA: " << GPA << endl;
    }
};

class Teacher : virtual public Person {
protected:
    int employeeID;
    string subject;

public:
    Teacher(const string& pname, int page, const string& paddress, int eid, const string& subj) 
        : Person(pname, page, paddress) {
        employeeID = eid;
        subject = subj;
    }

    void display() const override {
        Person::display();
        cout << "Employee ID: " << employeeID << "\nSubject: " << subject << endl;
    }
};

class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(const string& pname, int page, const string& paddress, int sid, double gpa, int eid, const string& subj)
        : Person(pname, page, paddress), Student(pname, page, paddress, sid, gpa), Teacher(pname, page, paddress, eid, subj) {}

    void modifyDetails(double newGPA, const string& newSubject) {
        GPA = newGPA;
        subject = newSubject;
    }

    void display() const override {
        Person::display();
        cout << "Student ID: " << studentID << "\nGPA: " << GPA << endl;
        cout << "Employee ID: " << employeeID << "\nSubject: " << subject << endl;
    }
};

int main() {
    TeachingAssistant ta("Alice Johnson", 25, "123 University St.", 202045, 3.8, 3001, "Mathematics");
    
    cout << "Teaching Assistant Details:" << endl;
    ta.display();

    cout << "\nModifying GPA and Subject..." << endl;
    ta.modifyDetails(3.9, "Computer Science");

    cout << "\nUpdated Teaching Assistant Details:" << endl;
    ta.display();

    return 0;
}
