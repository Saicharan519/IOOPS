#include <iostream>
using namespace std;

class Vector3D {
private:
    double x, y, z;

public:
    // Constructor to initialize vector elements
    Vector3D(double x_val = 0.0, double y_val = 0.0, double z_val = 0.0) 
        : x(x_val), y(y_val), z(z_val) {}

    // Overload * operator for dot product
    double operator*(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Overload ^ operator for cross product
    Vector3D operator^(const Vector3D& other) const {
        double cross_x = y * other.z - z * other.y;
        double cross_y = z * other.x - x * other.z;
        double cross_z = x * other.y - y * other.x;
        return Vector3D(cross_x, cross_y, cross_z);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& out, const Vector3D& v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }
};

int main() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);

    double dot_product = v1 * v2;
    cout << "Dot product: " << dot_product << endl;

    Vector3D cross_product = v1 ^ v2;
    cout << "Cross product: " << cross_product << endl;

    return 0;
}
