#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int l, n;
int rods[51];
int dp[51][51];

int solve_r(int i, int j) {
    if (i+1 == j) return 0;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = INF;
    for (int k = i+1; k < j; k++) {
        ret = min(ret, solve_r(i,k) + solve_r(k , j) + rods[j]-rods[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    while(true) {
        cin >> l;
        if (l == 0) break;
        cin >> n;
        rods[0] = 0; rods[n+1] = l;
        for (int i = 1; i <= n; ++i) cin >> rods[i];
        memset(dp, -1, sizeof(dp));
        cout << "The minimum cutting is " <<
             solve_r(0, n+1) << "." << endl;
    }
}