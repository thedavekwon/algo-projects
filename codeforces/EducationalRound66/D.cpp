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
    
    vector<int> nums;
    nums.reserve(n);
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    
    sort(nums.begin(), nums.end());
    long long cost1 = 0;
    long long cost2 = 0;
    long long cost = 0;
    if (n > k) {
        
    
    } else {
        for (int i = 0; i < n; i ++) {
            cost = cost + (i+1)*nums[i];
        }
    }
    cout << cost << endl;
}