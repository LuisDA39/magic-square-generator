#include <iostream>
#include <vector>

using namespace std;

void generarCuadro(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    // Fill the magic square
    int row = 0;
    int col = n / 2;

    for (int i = 1; i < 1 + n * n; i++) {
        square[row][col] = i;

        row--;
        col++;

        if (row < 0) {
            row = n - 1;
        }
        if (col == n) {
            col = 0;
        }

        if (square[row][col] != 0) {
            row += 2;
            col--;

            if (row >= n) {
                row -= n;
            }
            if (col < 0) {
                col = n - 1;
            }
        }
    }
}





void printMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;


    int m;
    cin >> m;



    // Print the magic square
    cout << "Magic square " << n << "x" << n << ":" << endl;
    printMatrix(square, n);

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

    return 0;
}
