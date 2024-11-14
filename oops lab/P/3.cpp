#include <iostream>
using namespace std;

class base {
public:
    int i;
    base(int x) : i(x) {}
    
    // Virtual function for polymorphism
    virtual void func() {
        cout << "Using base version of func(): " << i << '\n';
    }

    // Virtual destructor for proper cleanup of derived classes
    virtual ~base() {
        cout << "In base version destructor" << endl;
    }
};

class derived1 : public base {
public:
    derived1(int x) : base(x) {}

    // Overriding the base class function
    void func() override {
        cout << "Using derived1's version of func(): " << endl;
        cout << i * i << '\n';
    }

    ~derived1() {
        cout << "In derived1's destructor" << endl;
    }
};

class derived2 : public base {
public:
    derived2(int x) : base(x) {}

    // Overriding the base class function
    void func() override {
        cout << "Using derived2's version of func(): " << endl;
        cout << i + i << '\n';
    }

    ~derived2() {
        cout << "In derived2's destructor" << endl;
    }
};

class derived3 : public derived1 {
public:
    derived3(int x) : derived1(x) {}

    // Overriding the base class function
    void func() override {
        cout << "Using derived3's version of func(): " << endl;
        cout << i - i << '\n';
    }

    ~derived3() {
        cout << "In derived3's destructor" << endl;
    }
};

int main() {
    base* p; 
    base ob(10);
    derived1 d_ob1(10);
    derived2 d_ob2(10);
    derived3 d_ob3(10);

    cout << "Size of ob is " << sizeof(ob) << endl;
    cout << "Size of d_ob1 is " << sizeof(d_ob1) << endl;
    cout << "Size of d_ob2 is " << sizeof(d_ob2) << endl;
    cout << "Size of d_ob3 is " << sizeof(d_ob3) << endl;

    p = &ob; 
    p->func(); // Calls base's func()
    
    p = &d_ob1;  
    p->func(); // Calls derived1's func()
    
    p = &d_ob2;
    p->func(); // Calls derived2's func()

    p = &d_ob3; 
    p->func(); // Calls derived3's func()

    return 0;
}
