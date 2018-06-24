#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    int cnt = 0;
    int nums[3];
    cin >> tc;

    while(tc--) {
        for (int &num : nums) {
            cin >> num;
        }
        sort(nums, nums+3);
        cout << "Case " << ++cnt << ": " << nums[1] << endl;
    }
}