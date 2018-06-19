#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <limits>
#include <iomanip>

using namespace std;

int N, target;
int x[16], y[16];
double dp[1<<16];
double dist[16][16];

double solve_r(int mask) {
    if (mask == target) return 0;
    double &ret = dp[mask];
    if (ret != -1) return ret;
    ret = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i != j) && !(mask & (1<<i)) && !(mask & (1<<j))) {
                ret = min(ret, solve_r((mask | (1 << i) | (1 << j))) + dist[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(2) << fixed;
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    int cnt = 0;
    string tmp;
    while (true) {
        cnt++;
        cin >> tc;
        if (tc == 0) break;
        N = tc * 2;
        target = (1<<N)-1;
        for (int i = 0; i < N; ++i) {
            cin >> tmp;
            cin >> x[i];
            cin >> y[i];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = hypot(x[i]-x[j], y[i]-y[j]);
            }
        }
        fill(dp, dp+sizeof(dp)/sizeof(dp[0]), -1);
        cout << "Case " << cnt << ": " <<  solve_r(0) << endl;
    }
}