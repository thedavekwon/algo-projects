#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("./D.input");
    cin.rdbuf(in.rdbuf());

    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    vector<long long> sums;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums[i] = t;
    }

    long long sum = 0;
    for (int i = n-1; i >= 0; i--) {
        sum = sum + nums[i];
        if (i > 0) sums.push_back(sum);
    }

    long long ret = sum;
    
    sort(sums.begin(), sums.end());
    reverse(sums.begin(), sums.end());

    for (int i = 0; i < k-1; i++) {
        ret = ret + sums[i];
    }
    cout << ret << endl;
}