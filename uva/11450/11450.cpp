#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int m, c;

int choices[21];
int prices[21][21];
int dp[201][21];

void pprint() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int solve_r(int money, int item) {
//    cout << money << "," << item << endl;
    int &ret = dp[money][item];
    if (ret != -1) return ret;
    if (item == c) return money;
    ret = 0;
    for (int j = 0; j < choices[item]; ++j) {
        if (money + prices[item][j] <= m) {
            ret = max(ret, solve_r(money + prices[item][j], item + 1));
        }
    }
    return ret;
}

void reconstruct(int money, int item) {
    if (money < 0 || item == c) return;
    for (int i = 0; i < choices[item] ; i++) {
        if (solve_r(money+prices[item][i], item+1) == dp[money][item]) {
            if (item == c-1) cout << prices[item][i] << endl;
            else cout << prices[item][i] << " ";
            reconstruct(money+prices[item][i], item+1);
            break;
        }
    }
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
            cin >> choices[i];
            for (int j = 0; j < choices[i]; ++j) {
                cin >> prices[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve_r(0, 0);
        if (ans == 0) cout << "no solution" << endl;
        else cout << ans << endl;

        if (ans != 0) reconstruct(0, 0);
//        pprint();
    }
}