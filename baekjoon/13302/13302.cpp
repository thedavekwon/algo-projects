#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

int N, M;
int forbidden[101];
int dp[101][101];

int days[3]   = {1, 3, 5};
int prices[3] = {10000, 25000, 37000};
int coup[3]   = {0, 1, 2};

int solve_r(int day, int coupon) {
    if (day >= N+1) return 0;
    int &ret = dp[day][coupon];
    if (ret != -1) return ret;
    ret = numeric_limits<int>::max();
    for (int j = 0; j < M; ++j) {
        if (forbidden[j] == day) {
            ret = min(ret, solve_r(day+1, coupon));
            continue;
        }
    }
    for (int i = 0; i < 3; ++i) {
        ret = min(ret, prices[i] + solve_r(day+days[i], coupon+coup[i]));
    }
    if (coupon >= 3) ret = min(ret, solve_r(day+1, coupon-3));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> forbidden[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve_r(1, 0) << endl;
}