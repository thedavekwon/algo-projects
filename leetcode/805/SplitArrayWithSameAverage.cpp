#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, sum;
signed char	dp[30031][16];

bool splitArrayWithSameAverage(vector<int> &A, int target, int idx) {
    if (idx == 0) {
        if (target == 0) return true;
        return false;
    }
    if (target == sum * idx / A.size() && sum*idx % A.size() == 0) return true;
    signed char	 &ret = dp[target][idx];
    if (ret != -1) return ret;
    ret = 0;
    if (target - A[idx] < 0) ret = ret || splitArrayWithSameAverage(A, target - A[idx], idx - 1);
    ret = ret || splitArrayWithSameAverage(A, target, idx-1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    sum = accumulate(A.begin(), A.end(), 0);
    memset(dp, -1, sizeof(dp));
    cout << splitArrayWithSameAverage(A, sum, 1) << endl;
}