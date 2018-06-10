#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int INF = 999999998;

int N;
int x, y;
int beepers_x[11];
int beepers_y[11];
int dp[11][1<<11];
int dist[11][11];

int solve_r(int idx, int state) {
    if (state == (1<<(N+1))-1) return dist[idx][0];
    int &ret = dp[idx][state];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i <= N; ++i) {
        if (idx != i && (state & (1<<i))==0)
            ret = min(ret, dist[idx][i] + solve_r(i, state ^ (1<<i)));
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
        memset(dp, -1, sizeof(dp));
        cin >> x >> y;
        cin >> beepers_x[0] >> beepers_y[0];
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            cin >> beepers_x[i] >> beepers_y[i];
        }

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                dist[i][j] = abs(beepers_x[i]-beepers_x[j]) + abs(beepers_y[i]-beepers_y[j]);
            }
        }
        
        cout << "The shortest path has length " <<
             solve_r(0, 1) << endl;
    }
}
