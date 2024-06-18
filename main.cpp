#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateSquare(int n, char m) {
    vector<vector<int>> square(n, vector<int>(n, 0));
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
            cout << "Enter an integer x: ";
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
    cout << "Magic Square " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        int RowSum = 0;
        int ColSum = 0;

        for (int j = 0; j < n; j++) {
            RowSum += square[i][j];
            ColSum += square[j][i];
        }

        cout << "Sum of the row " << i + 1 << ": " << RowSum << endl;
        cout << "Sum of the column " << i + 1 << ": " << ColSum << endl;
    }

    int diagSum1 = 0;
    int diagSum2 = 0;

    for (int i = 0; i < n; i++) {
        diagSum1 += square[i][i];
        diagSum2 += square[i][n - i - 1];
    }

    cout << "Sum of the main diagonal: " << diagSum1 << endl;
    cout << "Sum of the secondary diagonal: " << diagSum2 << endl;
}

int main() {
    int n;

    do {
        cout << "Enter the square size: " << endl;
        cin >> n;

        if (n % 2 == 0)
            cout << "Square size must be odd" << endl;

    } while (n % 2 == 0);

    char m;
    cout << "------MENU-----" << endl;
    cout << "Option 'c' for consecutive numbers" << endl;
    cout << "Option 'p' for even numbers" << endl;
    cout << "Option 'i' for odd numbers" << endl;
    cout << "Option 'm' for multiples of x" << endl;
    cout << "Enter the option: " << endl;
    cin >> m;

    vector<vector<int>> square = generateSquare(n, m);
    printMatrix(square, n);

    return 0;
}
