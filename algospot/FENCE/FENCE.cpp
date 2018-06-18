#include <iostream>
#include <fstream>

using namespace std;

int N;
int heights[20001];

double solve_r(int start, int end) {
    if (start == end) return heights[start];
    int mid = (start + end) / 2;

    int left = solve_r(start, mid);
    int right = solve_r(mid+1, end);
    int ret = max(left, right);

    int i = 0, j = 1;
    int minimum_height = min(heights[mid-i], heights[mid+j]);
    ret = max(ret, minimum_height*2);
    while (true) {
        //cout << mid-i << "-" << mid+j << "   " << ret << endl;
        // expand to left
        if (mid-i > start && (mid+j == end || heights[mid-i-1] >= heights[mid+j+1])) {
            i++;
            minimum_height = min(minimum_height, heights[mid-i]);
            ret = max(ret, minimum_height * (i+j+1));
        }
        // expand to right
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
