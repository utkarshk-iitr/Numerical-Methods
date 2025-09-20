/* Simpson's Rule */
#include <iostream>
#include <iomanip>
using namespace std;

// Define the function to integrate
float y(float x) {
    return 1.0f / (1.0f + x * x);
}

int main() {
    float x0, xn, h, s;
    int i, n;

    cout << "Enter x0, xn, number of subintervals: ";
    cin >> x0 >> xn >> n;

    cout << fixed;

    h = (xn - x0) / n;
    s = y(x0) + y(xn) + 4 * y(x0 + h);

    for (i = 3; i <= n - 1; i += 2)
        s += 4 * y(x0 + i * h) + 2 * y(x0 + (i - 1) * h);

    cout << "Value of integral is " << setw(8) << setprecision(4) << (h / 3) * s << endl;

    return 0;
}
