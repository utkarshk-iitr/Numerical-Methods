/* Runge-Kutta Method */
#include <iostream>
#include <iomanip>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x + y * y;
}

int main() {
    float x0, y0, h, xn, x, y, k1, k2, k3, k4, k;

    cout << "Enter the values of x0, y0, h, xn" << endl;
    cin >> x0 >> y0 >> h >> xn;

    x = x0; 
    y = y0;

    cout << fixed;

    while (true) {
        if (x >= xn) break;

        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0f, y + k1 / 2.0f);
        k3 = h * f(x + h / 2.0f, y + k2 / 2.0f);
        k4 = h * f(x + h, y + k3);

        k = (k1 + 2.0f * (k2 + k3) + k4) / 6.0f;

        x += h;
        y += k;

        cout << "When x = " << setw(8) << setprecision(4) << x
             << " y = " << setw(8) << y << endl;
    }

    return 0;
}
