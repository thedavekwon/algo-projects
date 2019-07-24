#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("./C.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    vector<int> precalc;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    
    for (int i = 1; i < n; i++) {
        precalc.push_back(nums[i-1]-nums[i]);
    }
    
    sort(precalc.begin(), precalc.end());
    
    int ret = nums[n-1] - nums[0];
    
    for (int i = 0; i < k-1; i++) {
        ret = ret + precalc[i];
    }
    
    cout << ret << endl;
}