#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int s;

int dp[20001];
int road[20001];

void pprint() {
    for (int i = 0; i < s; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int solve(int idx) {
    int &ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == -1) return 0;
    return ret = max(solve(idx-1) + road[idx], 0);
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        for (int i = 0; i < s-1; ++i) {
            cin >> road[i];
        }
        cout << solve(s-1) << endl;
        pprint();
    }
}