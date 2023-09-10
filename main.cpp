#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarCuadro(int n, char m) {
    vector<vector<int>> cuadro(n, vector<int>(n, 0));
    // Llenado del cuadro magico
    int fila = 0;
    int col = n / 2;
    int x;

    switch(m) {
        case 'c':
            for (int i = 1; i < 1 + n * n; i++) {
                cuadro[fila][col] = i;
                fila--;
                col++;

                if (fila < 0)
                    fila = n - 1;
                if (col == n)
                    col = 0;

                if (cuadro[fila][col] != 0) {
                    fila += 2;
                    col--;
                    if (fila >= n)
                        fila -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'p':
            for (int i = 1; i < 1 + n * n; i++) {
                cuadro[fila][col] = 2 * i;
                fila--;
                col++;

                if (fila < 0)
                    fila = n - 1;
                if (col == n)
                    col = 0;

                if (cuadro[fila][col] != 0) {
                    fila += 2;
                    col--;
                    if (fila >= n)
                        fila -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'i':
            for (int i = 1; i < 2*(n * n); i += 2) {
                cuadro[fila][col] = i;

                fila--;
                col++;

                if (fila < 0)
                    fila = n - 1;
                if (col == n)
                    col = 0;

                if (cuadro[fila][col] != 0) {
                    fila += 2;
                    col--;
                    if (fila >= n)
                        fila -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        case 'm':
            cout << "Ingresa un entero x" << endl;
            cin >> x;

            for (int i = 1; i < 1 + n * n; i++) {
                cuadro[fila][col] = i * x;
                fila--;
                col++;

                if (fila < 0)
                    fila = n - 1;
                if (col == n)
                    col = 0;

                if (cuadro[fila][col] != 0) {
                    fila += 2;
                    col--;
                    if (fila >= n)
                        fila -= n;
                    if (col < 0)
                        col = n - 1;
                }
            }
            break;

        default:

            break;
    }
    return cuadro;
}

void printMatrix(vector<vector<int>>& cuadro, int n) {
    cout << "Cuadro Magico " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cuadro[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        int SumFila = 0;
        int SumCol = 0;

        for (int j = 0; j < n; j++) {
            SumFila += cuadro[i][j];
            SumCol += cuadro[j][i];
        }

        cout << "Suma de la fila " << i + 1 << ": " << SumFila << endl;
        cout << "Suma de la columna " << i + 1 << ": " << SumCol << endl;
    }

    int diagSum1 = 0;
    int diagSum2 = 0;

    for (int i = 0; i < n; i++) {
        diagSum1 += cuadro[i][i];
        diagSum2 += cuadro[i][n - i - 1];
    }

    cout << "Suma de la diagonal principal: " << diagSum1 << endl;
    cout << "Suma de la diagonal secundaria: " << diagSum2 << endl;
}

int main() {
    int n;
    cout << "Ingresa el tamano del cuadro" << endl;
    cin >> n;

    char m;
    cout << "------MENU-----" << endl;
    cout << "Opcion c para numeros consecutivos" << endl;
    cout << "Opcion p para numeros pares" << endl;
    cout << "Opcion i para numeros impares" << endl;
    cout << "Opcion m para numeros multiplos de x" << endl;
    cout << "Ingresa la opcion" << endl;
    cin >> m;

    vector<vector<int>> cuadro = generarCuadro(n, m);

    printMatrix(cuadro, n);

    return 0;
}
