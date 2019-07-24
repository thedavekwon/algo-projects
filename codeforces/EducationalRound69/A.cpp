#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream in("./A.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        vector<int> lens;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            lens.push_back(t);
        }
        sort(lens.begin(), lens.end(), greater<int>());
        cout << max(min(lens[1]-1, (int)lens.size()-2), 0) << endl; 
    }
}