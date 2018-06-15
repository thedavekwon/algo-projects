#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int triangles[101][101];
int dp[101][101];

void pprint() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solve_r(int i, int j) {
    if (i == n) return 0;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = -987654321;
    ret = max(ret, solve_r(i+1,j)+triangles[i][j]);
    ret = max(ret, solve_r(i+1,j+1)+triangles[i][j]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i+1; ++j) {
                cin >> triangles[i][j];
            }
        }
        cout << solve_r(0,0) << endl;
    }
}