#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int N;
int dp[101];

int solve_r(int idx) {
    if (idx == 0) return 1;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    return ret = (solve_r(idx-2) + solve_r(idx-1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    memset(dp, -1, sizeof(dp));
    while(tc--) {
        cin >> N;
        cout << solve_r(N) << endl;
    }
}