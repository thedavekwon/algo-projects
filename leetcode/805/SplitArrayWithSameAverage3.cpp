#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

bool splitArrayWithSameAverage(vector<int> &A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    bool dp[sum+1][A.size()/2+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    // iterate through all numbers
    for (int num : A) {
        // start with sum and until bigger than num
        for (int i = sum; i >= num; i--) {
            // try half of input array
            for (int j = 1; j <= A.size()/2; ++j) {
                dp[i][j] = dp[i][j] || dp[i-num][j-1];
            }
        }
    }
    for (int k = 1; k <= A.size()/2; ++k) {
        if (sum*k%A.size() == 0 && dp[sum*k/A.size()][k]) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << splitArrayWithSameAverage(A) << endl;
}