#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MOD = 1000000;

int N, K;
int dp[101][101];

int solve_r(int sum, int k) {
    //cout << sum << "," << k << endl;
    if (sum == N) return 1;
    if (k == K) return 0;
    int &ret = dp[sum][k];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= N; ++i) {
        if (sum + i <= N) ret = (ret + solve_r(sum+i, k+1))%MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    while (true) {
        cin >> N >> K;
        if (N == 0 && K == 0) break;
        memset(dp, -1, sizeof(dp));
        cout << solve_r(0, 0) << endl;
    }
}