#include <iostream>
#include <cmath>

using namespace std;

float circleArea(float radius) {
    return radius*radius*M_PI;
}

int main()
{
    float radius;
    cout << "Please enter the radius: ";
    cin >> radius;

    float area = circleArea(radius);

    cout << "The area of a circle with radius " << radius << " is " << area << endl;
    return 0;
}
