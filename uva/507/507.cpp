#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int s;

int dp[20001][20001];
int road[20001];

void pprint() {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int add(int i, int j){
    int sum = 0;
    for (int k = i; k < j; k++) {
        sum += road[k];
    }
    return sum;
}

int solve_r(int from, int to) {
    int &ret = dp[from][to];
    if (ret != -1) return ret;
    cout << from << "," << to << endl;
    if (from+1 == to) return road[from];
    if (from == s) return road[from];
    ret = 0;
    for (int i = from; i < to; i++) {
        for (int j = i+1; j <= to; j++) {
            ret = max(ret, solve_r(i, j) + add(from, i));
        }
    }
    return ret;
}

int solve() {
//    int ret = 0;
//    for (int i = 0; i < s-1; ++i) {
//        ret = max(ret, solve_r(i, s-1));
//        cout << "i: " << i << "   ret:" << ret << endl;
//    }
    return solve_r(0, s);
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
        cout << solve() << endl;
        pprint();
    }
}