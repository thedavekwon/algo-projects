#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    
    
}