#include<iostream>
using namespace std;

class triangle {
    int a, b, c;
    public:
    void getdata(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }
    void showdata(){
        if(a==b && b==c){
            cout << "Equilateral Triangle" << endl;
        }
        else if(a!=b && b!=c && c!=a){
            cout << " scalene Triangle" << endl;
        }
        else{
            cout << "Isosceles Triangle" << endl;
        }
    }
};

int main() {
    triangle T;
    int p, q, r;
    cout << "Enter sides of the triangle: ";
    cin >> p >> q >> r;
    T.getdata(p, q, r);
    T.showdata();
    return 0;

}