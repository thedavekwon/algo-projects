#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int nums[501];
int dp[501];

int solve_r(int idx) {
    if (idx == n) return 0;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = idx+1; i < n; ++i) {
        if (nums[i] > nums[idx]) ret = max(ret, solve_r(i)+1);
    }
    return ret;
}

int solve() {
    int largest = 0;
    for (int i = 0; i < n; ++i) {
        largest = max(largest, solve_r(i));
    }
    return largest;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve()+1 << endl;
    }
}