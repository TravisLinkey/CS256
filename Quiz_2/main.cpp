#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
    double pi = 3.14159;

public:

    Circle() {
        this->radius = 0.0;
    }
    Circle(double rad) {
        this->radius = rad;
    }

    void setRadius(double rad) {
        this->radius = rad;
    };
    double getRadius () {
        return radius;
    };
    double getDiameter() {
        return (radius * 2);
    };
    double getArea () {
        return (pi * radius * radius);
    };
    double getCircumference () {
        return (2 * pi * radius);
    };
};

int main() {
    double ans;

    cout << "Please input the radius of the circle\n";
    cin >> ans;
    Circle circle(ans);
    cout << "The AREA of the circle is: " << circle.getArea() << std::endl;
    cout << "The DIAMETER of the circle is: " << circle.getDiameter() << std::endl;
    cout << "The CIRCUMFERENCE of the circle is: " << circle.getCircumference() << std::endl;


    return 0;
}