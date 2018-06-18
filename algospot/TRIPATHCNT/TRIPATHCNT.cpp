#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int nums[101][101];
int dp[101][101];
int countCache[101][101];

void pprint() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double solve_r(int i, int j) {
    if (i == n) return 0;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = max(ret, solve_r(i+1,j)+nums[i][j]);
    ret = max(ret, solve_r(i+1,j+1)+nums[i][j]);
    return ret;
}

int count(int i, int j) {
    if (i == n-1) return 1;
    int &ret = countCache[i][j];
    if (ret != -1) return ret;
    ret = 0;
    if (solve_r(i+1, j+1) >= solve_r(i+1, j)) ret = ret + count(i+1, j+1);
    if (solve_r(i+1, j+1) <= solve_r(i+1, j)) ret = ret + count(i+1, j);
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
            for (int j = 0; j < i+1; ++j) {
                cin >> nums[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(countCache, -1, sizeof(countCache));
        cout << count(0, 0) << endl;
    }
}