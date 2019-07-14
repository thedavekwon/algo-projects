#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream in("./C.input");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;
    tc = tc;
    
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        int dist = 987654321;
        int ret = 0;
        for (int i = 0; i < n-k; i++) {
            int tmp = round(((double)nums[i]+nums[i+k])/2);
            int tmp_dist = max(tmp - nums[i], nums[i+k]-tmp);
            if (tmp_dist < dist) {
                dist = tmp_dist;
                ret = i;
            }
        }
        
        int tmp = round(((double)nums[ret]+nums[ret+k])/2);
        cout << tmp << endl;
    }
}