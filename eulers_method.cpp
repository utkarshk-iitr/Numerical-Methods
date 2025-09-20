/* Euler's Method */
#include <iostream>
#include <iomanip>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
float df(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, x, x1, y1;

    cout << "Enter the values of x0, y0, h, x" << endl;
    cin >> x0 >> y0 >> h >> x;

    cout << fixed;

    x1 = x0;
    y1 = y0;

    while (true) {
        if (x1 > x) return 0;

        y1 += h * df(x1, y1);
        x1 += h;

        cout << "When x = " << setw(6) << setprecision(1) << x1
             << " y = " << setw(8) << setprecision(2) << y1 << endl;
    }
}
