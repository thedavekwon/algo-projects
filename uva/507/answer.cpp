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

int add(int i, int j){
    int sum = 0;
    for (int k = i; k < j+1; k++) {
        sum += road[k];
    }
    return sum;
}

int solve_r(int idx) {
//    cout << idx << endl;
//    pprint();
    int &ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == s-1) return ret = 0;
    if (road[idx] > 0) return ret = solve_r(idx+1) + road[idx];
    else return ret = solve_r(idx+1) - road[idx];
}

int solve() {
    int ret = 0;
    for (int i = 0; i < s; ++i) {
        ret = max(ret, solve_r(i));
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
        cin >> s;
        for (int i = 0; i < s-1; ++i) {
            cin >> road[i];
        }
        cout << solve() << endl;
        pprint();
    }
}