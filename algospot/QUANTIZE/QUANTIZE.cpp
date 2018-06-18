#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>

int n, s;
int nums[101];

int dp[101][11];
using namespace std;

int error_square(int start, int end) {
    double sum = 0;
    for (int i = start; i < end; ++i) sum += nums[i];
    int avg = (start == 0) ? static_cast<int>(round(sum/end)) : static_cast<int>(round(sum/(end-start)));
    int ret = 0;
    for (int j = start; j < end; ++j) ret += static_cast<int>(pow(nums[j]-avg,2));
    return ret;
}

double solve_r(int idx, int q) {
    if (idx == n) return 0;
    if (q == s) return 987654321;
    int &ret = dp[idx][q];
    if (ret != -1) return ret;
//    if (q == s-1) return ret = error_square(idx, n);
    ret = 987654321;
    for (int i = idx+1; i <= n; ++i) {
        ret = min(ret, solve_r(i, q+1) + error_square(idx, i));
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
        cin >> n >> s;
        for (int i = 0; i < n; ++i) cin >> nums[i];
        sort(nums, nums+n);
        memset(dp, -1, sizeof(dp));
        cout << solve_r(0, 0) << endl;
    }
}