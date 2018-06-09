#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int N, G;

int dp[40][1010];
int prices[1010];
int weights[1010];
int persons[110];

int solve_r(int weight, int idx) {
    int &ret = dp[weight][idx];
    if (ret != -1) return ret;
    if (idx == N || weight == 0) return 0;
    if (weight-weights[idx] >= 0)
        return ret = max(solve_r(weight, idx+1), solve_r(weight-weights[idx], idx+1) + prices[idx]);
    return ret = solve_r(weight, idx+1);
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
            cin >> weights[i];
        }
        cin >> G;
        for (int j = 0; j < G; ++j) {
            cin >> persons[j];
        }
        int ans = 0;
        for (int k = 0; k < G; ++k) {
            ans = ans + solve_r(persons[k], 0);
        }
        cout << ans << endl;
    }
}