#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int m, c;

int coins[101];
int dp[5001][101];

void pprint() {
    for (int i = 0; i <= m; ++i) {
        cout << i << ": ";
        for (int j = 0; j <= c; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double solve_r(int price, int coin) {
//    cout << price <<',' << coin << endl;
    int &ret = dp[price][coin];
    if (ret != -1) return ret;
    if (price == 0) return ret = 1;
    ret = 0;
    for (int i = coin; i < c; i++) {
        if (price-coins[i] >= 0) {
            ret = (ret + solve_r(price-coins[i], i)) % MOD;
        }
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
        cin >> m >> c;
        for (int i = 0; i < c; ++i) {
            cin >> coins[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve_r(m, 0) << endl;
//        pprint();
    }
}