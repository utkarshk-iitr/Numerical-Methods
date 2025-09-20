/* Gauss-Jordan method */
#include <iostream>
#include <iomanip>
using namespace std;

#define N 4

int main() {
    float a[N][N + 1], t;
    int i, j, k;

    cout << "Enter the elements of the augmented matrix rowwise" << endl;
    for (i = 0; i < N; i++)
        for (j = 0; j < N + 1; j++)
            cin >> a[i][j];

    cout << fixed;

    // Transforming matrix to diagonal form
    for (j = 0; j < N; j++)
        for (i = 0; i < N; i++)
            if (i != j) {
                t = a[i][j] / a[j][j];
                for (k = 0; k < N + 1; k++)
                    a[i][k] -= a[j][k] * t;
            }

    // Print the diagonal matrix
    cout << "The diagonal matrix is:-" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N + 1; j++)
            cout << setw(9) << setprecision(4) << a[i][j];
        cout << endl;
    }

    // Print the solution
    cout << "The solution is:- " << endl;
    for (i = 0; i < N; i++)
        cout << "x[" << setw(3) << i + 1 << "] = " << setw(7) << setprecision(4) << a[i][N] / a[i][i] << endl;

    return 0;
}
