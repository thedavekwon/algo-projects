#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n, m;
double dp[1001][2*1001+1];

double solve_r(int i, int j) {
    if (i == m) return j >= n ? 1 : 0;
    double &ret = dp[i][j];
    if (ret != -1.0) return ret;
    return ret = 0.75 * solve_r(i+1, j+2) +  0.25 * solve_r(i+1, j+1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 2*m+1; ++j) {
                dp[i][j] = -1.0;
            }
        }
        cout << solve_r(0, 0) << endl;
    }
}