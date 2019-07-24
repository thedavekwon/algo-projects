#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("./B.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> disks;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mx = max(t, mx);
        disks.push_back(t);
    }
    
    int max_idx = distance(disks.begin(), max_element(disks.begin(), disks.end()));
    for (int i = 0; i < max_idx; i++) {
        if (disks[i] > disks[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = max_idx+1; i < n-1; i++) {
        if (disks[i] < disks[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}