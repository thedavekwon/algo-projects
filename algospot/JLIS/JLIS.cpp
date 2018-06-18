#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

int n, m;
int A[101];
int B[101];
int dp[101][101];

void pprint() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double solve_r(int aIdx, int bIdx) {
    int &ret = dp[aIdx+1][bIdx+1];
    if (ret != -1) return ret;
    ret = 2;
    long long a = (aIdx == -1 ? numeric_limits<long long>::min() : A[aIdx]);
    long long b = (bIdx == -1 ? numeric_limits<long long>::min() : B[bIdx]);
    long long maximum = max(a, b);

    for (int i = aIdx+1; i < n; ++i) {
//        if ((A[i] < A[aIdx] && A[i] > B[bIdx]) || (A[i] > A[aIdx] && A[i] < B[bIdx]) || (A[i] > A[aIdx] && A[i] > B[bIdx]))
        if (A[i] >  maximum) ret = max(ret, solve_r(i, bIdx) + 1);
    }
    for (int j = bIdx+1; j < m; ++j) {
//        if ((B[j] < B[bIdx] && B[j] > A[aIdx]) || (B[j] > B[bIdx] && B[j] < A[aIdx]) || (B[j] > B[bIdx] && B[j] > A[aIdx]))
        if (B[j] > maximum) ret = max(ret, solve_r(aIdx, j) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> B[j];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve_r(-1, -1)-2 << endl;
    }
}