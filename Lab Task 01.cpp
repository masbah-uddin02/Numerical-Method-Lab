//1. Write a C++ program to find the real root up to 3 decimal places of the equation x^3-x-4=0 using False Position Method.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double equation(double x) {
    return pow(x, 3) - x - 4;
}

double falsePositionMethod(double a, double b, double epsilon) {
    double c = a;
    while ((b - a) >= epsilon) {

        double fa = equation(a);
        double fb = equation(b);


        c = (a * fb - b * fa) / (fb - fa);


        double fc = equation(c);


        if (fabs(fc) < epsilon)
            break;


        if (fa * fc < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double epsilon = 0.001;

    double root = falsePositionMethod(a, b, epsilon);

    cout << "The root of the equation x^3 - x - 4 = 0 is: " << fixed << setprecision(3) << root << endl;

    return 0;
}
