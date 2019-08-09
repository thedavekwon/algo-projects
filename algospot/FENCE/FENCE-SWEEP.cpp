#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int solve_sweep(vector<int> &heights);

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }
        cout << solve_sweep(heights) << endl;
    }
}

int solve_sweep(vector<int> &heights) {
    stack<int> remaining;
    heights.push_back(0);
    
    int ret = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!remaining.empty() && heights[remaining.top()] >= heights[i]) {
            int j = remaining.top();
            remaining.pop();
            int width;
            if (remaining.empty()) {
                width = i;
            } else {
                width = (i-remaining.top() -1);
            }
            ret = max(ret, heights[j]*width);
        }
        remaining.push(i);
    }
    return ret;
}