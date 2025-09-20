/* Newton's Divided Difference Interpolation */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of observations: ";
    cin >> n;

    double x[10], y[10], p[10];
    cout << "Enter the different values of x:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter the corresponding values of y:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    cout << "Enter the value of k for which you want to evaluate f(k): ";
    cin >> k;

    double f = y[0];
    double f2 = 0, f1;

    int size = n;
    int j = 1;

    while (size != 1) {
        // Calculate divided differences
        for (int i = 0; i < size - 1; i++) {
            p[i] = (y[i + 1] - y[i]) / (x[i + j] - x[i]);
            y[i] = p[i];
        }

        // Compute the product term for Newton's formula
        f1 = 1.0;
        for (int i = 0; i < j; i++) f1 *= (k - x[i]);

        f2 += y[0] * f1;
        j++;
        size--;
    }

    f += f2;
    cout << fixed << setprecision(4);
    cout << "f(" << k << ") = " << f << endl;

    return 0;
}
