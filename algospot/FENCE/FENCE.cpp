#include <iostream>
#include <fstream>

using namespace std;

int N;
int heights[20001];

// start with (0, N-1) -> (0, (N-1)/2)
//                     -> ((N-1)/2+1, N-1)
// check with individual first 

int solve_r(int start, int end) {
    if (start == end) return heights[start];
    int mid = (start + end) / 2;

    int left = solve_r(start, mid);
    int right = solve_r(mid+1, end);
    int ret = max(left, right);

    // first check with mid and mid+1
    int i = 0, j = 1;
    int minimum_height = min(heights[mid-i], heights[mid+j]);
    // starts with mid and mid+1
    ret = max(ret, minimum_height*2);
    while (true) {
        // if you can still expand to the left and (right is already all expaneded or mid-i-1 is bigger than the mid+j+1[expands to larger one]), expand to left
        if (mid-i > start && (mid+j == end || heights[mid-i-1] >= heights[mid+j+1])) {
            i++;
            minimum_height = min(minimum_height, heights[mid-i]);
            ret = max(ret, minimum_height * (i+j+1));
        }
        // if you can still expand to the right, expand to right
        else if (mid + j < end) {
            j++;
            minimum_height = min(minimum_height, heights[mid+j]);
            ret = max(ret, minimum_height * (i+j+1));
        }
        else break;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }
        cout << solve_r(0, N-1) << endl;
    }
}
