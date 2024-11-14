#include<iostream>

using namespace std;

class complexnumber{
    int real, imag;
    public:
    complexnumber(){}
    complexnumber(int r, int i){
        real = r;
        imag = i;
    }
    void printnumber(){
        cout << "your number is" << real << " + " << imag << "i" << endl;
    }
    void sum(complexnumber o1, complexnumber o2){
        complexnumber o3(o1.real + o2.real, o1.imag + o2.imag);
        o3.printnumber();
    }
    void subt(complexnumber o1, complexnumber o2){
        complexnumber o3(o1.real - o2.real, o1.imag - o2.imag);
        o3.printnumber();
    }
};

int main(){
    int x, y;
    cout << "Enter real part and imaginary part of fist complex" << endl;
    cin >> x >> y;
    complexnumber c1(x, y);
    c1.printnumber();
    cout << "Enter real part and imaginary part of second complex" << endl;
    cin >> x >> y;
    complexnumber c2(x, y);
    c2.printnumber();
    cout << "sum of complex is" << endl;
    c1.sum(c1, c2);
    cout << "subtraction of complex is" << endl;
    c1.subt(c1, c2);
    return 0;
    
}