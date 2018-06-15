#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int board[101][101];
int dp[101][101];

int solve_r(int i, int j) {
    if (i == n-1 && j == n-1) return 1;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 0;
    if (i+board[i][j] < n) ret = ret || solve_r(i+board[i][j], j);
    if (j+board[i][j] < n) ret = ret || solve_r(i, j+board[i][j]);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));

        int ans = solve_r(0, 0);
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}