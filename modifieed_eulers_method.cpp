/* Modified Euler's Method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float x, y, x1 = 0.0f, y1 = 0.0f, h, ms = 0.0f, y2 = 0.0f, t = 0.0f;
    bool flag = false;
    int i;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Enter the step size h: ";
    cin >> h;

    cout << fixed;
    cout << setw(5) << "x" << setw(15) << "x+y=y1" 
         << setw(15) << "Mean slope" << setw(25) << "New y" << endl;

    while (x1 < x) {
        do {
            if (!flag) {
                y1 = x1 + y;
                ms = y1;
                y2 = y + h * ms;
                x1 += h;
                flag = true;

                cout << setw(5) << x1 << setw(15) << y1 
                     << setw(15) << ms << setw(25) << y2 << endl;
            } else {
                ms = (y1 + (x1 + y2)) / 2.0f;
                t = y + h * ms;

                if (fabs(y2 - t) < 1e-6) {
                    y2 = t;
                    break;
                }

                y2 = y + h * ms;
                cout << setw(5) << x1 << setw(15) << x1 + y2 
                     << setw(15) << ms << setw(25) << y2 << endl;
            }
        } while (true);

        y = y2;
        flag = false;
    }

    cout << "\nFinal value: y(" << x << ") = " << y << endl;
    return 0;
}
