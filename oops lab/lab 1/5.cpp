#include<iostream>
#include<string>

using namespace std;

class date{
    string day;
    int month, year;
    public:
    void set(string x, int y, int z) {
        day = x;
        month = y;
        year = z;
    }
    void get(){
        if((day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == "sunday") &&(month > 0 && month < 13)){
            cout << day << "/" << month << "/" << year << endl;
        }
        else{
            cout << "Invalid " << endl;
        }
    }
};

int main(){
    date d;
    string x;
    int y, z;
    cout << "Enter date (day, month, year): ";
    cin >> x >> y >> z;
    d.set(x, y, z);
    d.get();
    return 0;
}