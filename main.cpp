//Adam Koziana
#include <iostream>
using namespace std;

long long calcDet(int A[][32], bool excluded[32], int n, int dim) {
    if (n == 1) {
        for (int i = 0; i < dim; i++) {
            if (!excluded[i]) {
                return A[0][i];
            }
        }
    }

    int sum = 0;
    int count = 0;
    if (n > 1) {
        for (int i = 0; i < dim && count < n; i++) {
            if (excluded[i]) {
                continue;
            }

            if (A[0][i] != 0) {
                excluded[i] = true;
                sum += A[0][i] * calcDet(A + 1, excluded, n - 1, dim) * (count % 2 == 0 ? 1 : -1);
                excluded[i] = false;
            }
            count++;
        }
    }
    return sum;
}

long long bareiss(int matrix[][32], int size) {
    if (size <= 0) {
        return 0;
    }
    int sign = 1;

    for (int k = 0; k < size - 1; k++) {
        if (matrix[k][k] == 0) {
            for (int z = k + 1; z < size; z++) {
                if (matrix[z][k] != 0) {
                    for (int j = 0; j < size; j++) {
                        swap(matrix[z][j], matrix[k][j]);
                    }
                    sign = -sign;
                    break;
                }
            }
            if (matrix[k][k] == 0) {
                return 0;
            }
        }
        for (int i = k + 1; i < size; i++) {
            for (int j = k + 1; j < size; j++) {
                matrix[i][j] = matrix[k][k] * matrix[i][j] - matrix[i][k] * matrix[k][j];
                if (k != 0) {
                    matrix[i][j] /= matrix[k - 1][k - 1];
                }
            }
        }
    }

    return sign * matrix[size - 1][size - 1];
}

int main() {
    int apexSize = 0;
    int maxDepth = 32;

    int cube[32][32][32];
    char userChoice = ' ';

    cin >> apexSize;

    for (int i = 0; i < apexSize; i++) {
        for (int j = 0; j < apexSize; j++) {
            for (int k = 0; k < apexSize; k++) {
                cin >> cube[i][j][k];
            }
        }
    }

    while (userChoice != 'E') {
        cin >> userChoice;

        if (userChoice == 'C') {
            int total = 0, l = 0, v = 0, p = 0, h = 0, w = 0, d = 0;
            cin >> l >> v >> p >> h >> w >> d;

            int newHeight = (l < apexSize / 2) ? l + h : l - h;
            int newWidth = (v < apexSize / 2) ? v + w : v - w;
            int newDepth = (p < apexSize / 2) ? p + d : p - d;

            if (l > newHeight) swap(l, newHeight);
            if (v > newWidth) swap(v, newWidth);
            if (p > newDepth) swap(p, newDepth);

            for (int i = p; i <= newDepth; i++) {
                for (int j = l; j <= newHeight; j++) {
                    for (int k = v; k <= newWidth; k++) {
                        if (i >= 0 && i < apexSize && j >= 0 && j < apexSize && k >= 0 && k < apexSize) {
                            total += cube[i][j][k];
                        }
                    }
                }
            }

            cout << total << endl;

        } else if (userChoice == 'T') {
            int l = 0, v = 0, p = 0, e = 0;
            cin >> l >> v >> p >> e;

            int newHeight = (l < apexSize / 2) ? l + e : l - e;
            int newWidth = (v < apexSize / 2) ? v + e : v - e;
            int newDepth = (p < apexSize / 2) ? p + e : p - e;

            if (l > newHeight) swap(l, newHeight);
            if (v > newWidth) swap(v, newWidth);
            if (p > newDepth) swap(p, newDepth);

            int total = 0;
            for (int i = p; i <= newDepth; i++) {
                for (int j = l; j <= newHeight; j++) {
                    for (int k = v; k <= newWidth; k++) {
                        if (i >= 0 && i < apexSize && j >= 0 && j < apexSize && k >= 0 && k < apexSize) {
                            if ((i - p) + (j - l) + (k - v) <= e) {
                                total += cube[i][j][k];
                            }
                        }
                    }
                }
            }
            cout << total << endl;

        } else if (userChoice == 'D') {
            int subMatrix[32][32];
            int index=0;
            char axis;

            cin >> axis >> index;
            if (axis == 'E') break;

            if (axis == 'l') {
                for (int x = 0; x < apexSize; x++) {
                    for (int y = 0; y < apexSize; y++) {
                        subMatrix[x][y] = cube[x][index][y];
                    }
                }
            } else if (axis == 'v') {
                for (int x = 0; x < apexSize; x++) {
                    for (int y = 0; y < apexSize; y++) {
                        subMatrix[x][y] = cube[x][y][index];
                    }
                }
            } else if (axis == 'p') {
                for (int x = 0; x < apexSize; x++) {
                    for (int y = 0; y < apexSize; y++) {
                        subMatrix[x][y] = cube[index][x][y];
                    }
                }
            }

            bool excluded[32] = {};
            if (apexSize >= 11) {
                cout << bareiss(subMatrix, apexSize) << endl;
            } else {
                cout << calcDet(subMatrix, excluded, apexSize, apexSize) << endl;
            }

        } else if (userChoice == 'O') {
            int total = 0, l = 0, v = 0, p = 0, r = 0;
            cin >> l >> v >> p >> r;

            int newHeight = (l < apexSize / 2) ? l + r : l - r;
            int newWidth = (v < apexSize / 2) ? v + r : v - r;
            int newDepth = (p < apexSize / 2) ? p + r : p - r;

            if (l > newHeight) swap(l, newHeight);
            if (v > newWidth) swap(v, newWidth);
            if (p > newDepth) swap(p, newDepth);

            for (int i = p; i <= newDepth; i++) {
                for (int j = l; j <= newHeight; j++) {
                    for (int k = v; k <= newWidth; k++) {
                        if (i >= 0 && i < apexSize && j >= 0 && j < apexSize && k >= 0 && k < apexSize) {
                            int distance = (i - p) * (i - p) + (j - l) * (j - l) + (k - v) * (k - v);
                            if (distance <= (r * r)) {
                                total += cube[i][j][k];
                            }
                        }
                    }
                }
            }

            cout << total << endl;
        }
    }
    return 0;
}