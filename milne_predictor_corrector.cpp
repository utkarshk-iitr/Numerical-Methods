/* Milne Predictor-Corrector Method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float x[5], y[5], h;

// Define the differential equation dy/dx = f(x, y)
float f(int i) {
    return x[i] - y[i] * y[i];
}

// Corrector function
void correct(int idx) {
    y[4] = y[2] + (h / 3.0f) * (f(2) + 4.0f * f(3) + f(4));
    cout << setw(23) << "" << setw(8) << setprecision(4) << y[4]
         << setw(8) << f(4) << endl;
}

int main() {
    float xr, aerr, yc;
    int i;

    cout << "Enter the values of x0, xr, h, allowed error" << endl;
    cin >> x[0] >> xr >> h >> aerr;

    cout << "Enter the values of y[i], i=0 to 3" << endl;
    for (i = 0; i <= 3; i++) cin >> y[i];

    cout << fixed;

    // Initialize x values
    for (i = 1; i <= 3; i++) x[i] = x[0] + i * h;

    // Print header
    cout << setw(5) << "x" << setw(15) << "Predicted" << setw(17) << "Corrected" << endl;
    cout << setw(11) << "y" << setw(10) << "f" << setw(7) << "y" << setw(10) << "f" << endl;

    while (true) {
        if (x[3] >= xr) return 0;

        x[4] = x[3] + h;

        // Predictor formula
        y[4] = y[0] + (4.0f * h / 3.0f) * (2.0f * (f(1) + f(3)) - f(2));

        cout << setw(6) << setprecision(2) << x[4]
             << setw(8) << setprecision(4) << y[4]
             << setw(8) << f(4) << endl;

        // First correction
        correct(1);

        // Iterative correction
        while (true) {
            yc = y[4];
            correct(1);
            if (fabs(yc - y[4]) <= aerr) break;
        }

        // Shift arrays for next step
        for (i = 0; i <= 3; i++) {
            x[i] = x[i + 1];
            y[i] = y[i + 1];
        }
    }
}
