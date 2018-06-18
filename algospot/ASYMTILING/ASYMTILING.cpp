#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int n;
int dp[101];

int solve_r(int idx) {

}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    memset(dp, -1, sizeof(dp));
    while(tc--) {
        cin >> n;
        cout << solve_r(n) << endl;
    }
}