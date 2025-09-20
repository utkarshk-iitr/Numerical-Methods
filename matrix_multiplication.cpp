/* Multiplication of matrices */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define MAX 20
typedef float matrix[MAX][MAX];

void getelems(matrix x, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> x[i][j];
}

void printsol(matrix x, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) cout << setw(5) << setprecision(1) << x[i][j];
        cout << endl;
    }
}

void matmul(matrix a, matrix b, matrix c, int l, int m, int p, int q) {
    float s;
    int i, j, k;

    cout << "Enter the elements of the first matrix" << endl;
    getelems(a, l, m);

    cout << "Enter the elements of the second matrix" << endl;
    getelems(b, p, q);

    for (i = 0; i < l; i++)
        for (j = 0; j < q; j++) {
            s = 0;
            for (k = 0; k < m; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }

    cout << "The solution is" << endl;
    printsol(c, l, q);
}

int main() {
    matrix a, b, c;
    int l, m, p, q;

    cout << "Enter the row, column of the first matrix" << endl;
    cin >> l >> m;

    cout << "Enter the row, column of the second matrix" << endl;
    cin >> p >> q;

    cout << fixed;

    if (m != p) {
        cout << "The two matrices cannot be multiplied" << endl;
        return 1;
    } else {
        matmul(a, b, c, l, m, p, q);
        return 0;
    }
}
