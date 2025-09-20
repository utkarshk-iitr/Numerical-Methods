/* Derivatives using Forward Difference */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int max, pos = 0;
    float xval, h, p, x0, y0, sum;

    cout << "Enter the number of data points: ";
    cin >> max;

    float* x = new float[max];
    float* y = new float[max];

    cout << "Enter the values in the table for x and y:\n";
    for (int i = 0; i < max; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    cout << "Enter the value of x to evaluate derivative at: ";
    cin >> xval;

    // Find the position
    for (int i = 0; i < max; i++) {
        if (x[i] >= xval) {
            pos = i;
            break;
        }
    }

    x0 = x[pos];
    y0 = y[pos];

    cout << "\nx0 = " << x0 << ", y0 = " << y0 << " at position " << pos << endl;

    h = x[1] - x[0];
    p = (xval - x0) / h;

    int l = max - pos;
    float* tmp = new float[l * l]{0};

    // Copy y values into first column
    for (int i = 0, j = pos; i < l; i++, j++)
        tmp[i] = y[j];

    // Build forward difference table
    for (int i = 1; i < l; i++)
        for (int j = 0; j < l - i; j++)
            tmp[i * l + j] = tmp[(i - 1) * l + j + 1] - tmp[(i - 1) * l + j];

    // Display forward difference table
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < l; i++) {
        cout << x[i + pos] << "\t";
        for (int j = 0; j < l; j++)
            cout << setw(8) << setprecision(3) << tmp[j * l + i] << "\t|";
        cout << "\n";
    }

    // First derivative using Newton's forward difference
    sum = 0;
    int k = 1;
    for (int i = 1; i < l; i++) {
        sum += (1.0 / i) * tmp[i * l + 0] * k;
        k = -k;
    }
    cout << "\nFirst derivative (dy/dx) = " << sum / h << endl;

    // Second derivative using forward differences
    int v[] = {0, 0, 1, 1, 11 / 12, 5 / 6, 137 / 180};
    sum = 0;
    k = 1;
    for (int i = 2; i < l; i++) {
        sum += v[i] * tmp[i * l + 0] * k;
        k = -k;
    }
    cout << "Second derivative (d2y/dx2) = " << sum / (h * h) << endl;

    delete[] x;
    delete[] y;
    delete[] tmp;

    return 0;
}
