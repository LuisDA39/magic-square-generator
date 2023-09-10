#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarCuadro(int n, char m) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    // Fill the magic square
    int row = 0;
    int col = n / 2;

    int x;

    switch(m) {
        case 'c':
            for (int i = 1; i < 1 + n * n; i++) {
                square[row][col] = i;
                row--;
                col++;

                if (row < 0)
                    row = n - 1;
                if (col == n)
                    col = 0;

                if (square[row][col] != 0) {
                    row += 2;
                    col--;
                    if (row >= n)
                        row -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'p':
            for (int i = 1; i < 1 + n * n; i++) {
                square[row][col] = 2 * i;
                row--;
                col++;

                if (row < 0)
                    row = n - 1;
                if (col == n)
                    col = 0;

                if (square[row][col] != 0) {
                    row += 2;
                    col--;
                    if (row >= n)
                        row -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'i':
            for (int i = 1; i < 2*(n * n); i += 2) {
                square[row][col] = i;

                row--;
                col++;

                if (row < 0)
                    row = n - 1;
                if (col == n)
                    col = 0;

                if (square[row][col] != 0) {
                    row += 2;
                    col--;
                    if (row >= n)
                        row -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'm':
            cin >> x;

            for (int i = 1; i < 1 + n * n; i++) {
                square[row][col] = i * x;
                row--;
                col++;

                if (row < 0)
                    row = n - 1;
                if (col == n)
                    col = 0;

                if (square[row][col] != 0) {
                    row += 2;
                    col--;
                    if (row >= n)
                        row -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        default:

            break;
    }
    return square;
}

void printMatrix(vector<vector<int>>& square, int n) {
    cout << "Magic square " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;

        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }

        cout << "Row sum " << i + 1 << ": " << rowSum << endl;
        cout << "Column sum " << i + 1 << ": " << colSum << endl;
    }

    int diagSum1 = 0;
    int diagSum2 = 0;

    for (int i = 0; i < n; i++) {
        diagSum1 += square[i][i];
        diagSum2 += square[i][n - i - 1];
    }

    cout << "Main diagonal sum: " << diagSum1 << endl;
    cout << "Secondary diagonal sum: " << diagSum2 << endl;
}

int main() {
    int n;
    cin >> n;

    char m;
    cin >> m;

    vector<vector<int>> square = generarCuadro(n, m);

    // Print the magic square
    printMatrix(square, n);

    return 0;
}
