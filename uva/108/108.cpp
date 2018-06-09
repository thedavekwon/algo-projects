#include <iostream>
#include <fstream>

using namespace std;

int N;
int matrix[101][101];

void toCumulative() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i > 0) matrix[i][j] += matrix[i-1][j];
            if (j > 0) matrix[i][j] += matrix[i][j-1];
            if (i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
        }
    }
}

int solve() {
    int ans = -127 * 100 * 100;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = i; k < N; ++k) {
                for (int l = j; l < N; ++l) {
                    int rect = matrix[k][l];
                    if (i > 0) rect -= matrix[i-1][l];
                    if (j > 0) rect -= matrix[k][j-1];
                    if (i > 0 && j > 0) rect += matrix[i-1][j-1];
                    ans = max(ans, rect);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    toCumulative();
    int ans = solve();
    cout << ans << endl;
}