#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double rectLength, double rectWidth) {
        length = rectLength;
        width = rectWidth;
    }

    Rectangle(const Rectangle &rect) {
        length = rect.length;
        width = rect.width;
    }

    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    void displayDetails() const {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    Rectangle rect1(10.0, 5.0);
    cout << "Rectangle 1 Details:" << endl;
    rect1.displayDetails();

    Rectangle rect2 = rect1;
    cout << "\nRectangle 2 Details (Copy of Rectangle 1):" << endl;
    rect2.displayDetails();

    return 0;
}
