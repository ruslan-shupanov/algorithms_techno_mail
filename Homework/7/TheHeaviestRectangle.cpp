#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>

using namespace:: std;

const long long int min_value = LLONG_MIN;

vector<vector<long long int>> prepareMatrix(vector<vector<long long int>> &matrix, int N, int M) {
    vector<vector<long long int>> sumMatrix(N, vector<long long int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) {
                sumMatrix[i][j] = matrix[i][j];
            } else if (j == 0) {
                sumMatrix[i][j] = sumMatrix[i - 1][j] + matrix[i][j];
            } else if (i == 0) {
                sumMatrix[i][j] = sumMatrix[i][j - 1] + matrix[i][j];
            } else {
                sumMatrix[i][j] = sumMatrix[i - 1][j] +
                                  sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1] +
                                  matrix[i][j];
            }
        }
    }
    return sumMatrix;
}

long long int execute(vector<vector<long long int>> &sumMatrix, int i1, int i2, int j1, int j2) {
    if (i1 == 0 && j1 == 0) {
        return sumMatrix[i2][j2];
    } else if (i1 == 0) {
        return sumMatrix[i2][j2] - sumMatrix[i2][j1 - 1];
    } else if (j1 == 0) {
        return sumMatrix[i2][j2] - sumMatrix[i1 - 1][j2];
    } else {
        return sumMatrix[i2][j2] - sumMatrix[i2][j1 - 1] - sumMatrix[i1 - 1][j2] + sumMatrix[i1 - 1][j1 - 1];
    }
}

long long int maxMatrix(vector<vector<long long int>> &m, int N, int M) {
    long long int maxArea = min_value;
    auto matrix = prepareMatrix(m, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int col1 = 0; col1 < M; col1++) {
                for (int col2 = col1; col2 < M; col2++) {
                    maxArea = max(maxArea, execute(matrix, i, j, col1, col2));
                }
            }
        }
    }
    return maxArea;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<long long int>> matrix(N, vector<long long int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }
    auto res = maxMatrix(matrix, N, M);
    cout << res << endl;
    return 0;
}
