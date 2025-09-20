/* Muller's Method */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define I 2

float y(float x) { return cos(x) - x * exp(x); }

int main() {
    int i, itr, maxitr;
    float x[4], li, di, mu, s, l, aerr;

    cout << "Enter the initial approximations" << endl;
    for (i = I - 2; i < 3; i++) cin >> x[i];

    cout << "Enter allowed error, maximum iterations" << endl;
    cin >> aerr >> maxitr;
    cout << fixed;

    for (itr = 1; itr <= maxitr; itr++) {
        li = (x[I] - x[I - 1]) / (x[I - 1] - x[I - 2]);
        di = (x[I] - x[I - 2]) / (x[I - 1] - x[I - 2]);
        mu = y(x[I - 2]) * li * li - y(x[I - 1]) * di * di + y(x[I]) * (di + li);
        s = sqrt(mu * mu - 4.0f * y(x[I]) * di * li * (y(x[I - 2]) * li - y(x[I - 1]) * di + y(x[I])));
        l = (mu < 0.0f) ? (2.0f * y(x[I]) * di) / (-mu + s) : (2.0f * y(x[I]) * di) / (-mu - s);
        x[I + 1] = x[I] + l * (x[I] - x[I - 1]);

        cout << "Iteration no. " << setw(3) << itr << " X = " << setw(7) << setprecision(5) << x[I + 1] << endl;

        if (fabs(x[I + 1] - x[I]) < aerr) {
            cout << "After " << setw(3) << itr << " iterations, the solution is " << setw(6) << setprecision(4) << x[I + 1] << endl;
            return 0;
        }

        for (i = I - 2; i < 3; i++) x[i] = x[i + 1];
    }

    cout << "Iterations not sufficient, solution does not converge" << endl;
    return 1;
}
