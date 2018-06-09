#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int coins[5] = {1, 5, 10, 25, 50};
int dp[7500][5];

int solve_r(int money, int idx) {
    int &ret = dp[money][idx];
    if (money == 0) return 1;
    if (money < 0 || idx == 5) return 0;
    if (ret != -1) return ret;
    return ret = solve_r(money, idx+1) + solve_r(money-coins[idx], idx);
}

int main() {
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    while(cin >> N) {
        cout << solve_r(N, 0) << endl;
    }
}