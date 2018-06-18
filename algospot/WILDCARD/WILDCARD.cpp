#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int n;
string pattern;
vector<string> words;
string word;
int dp[101][101];

double solve_r(int m, int n) {
    //cout << m << ',' << n << endl;
    if (m == pattern.length() && n == word.length()) return 1;
    int &ret = dp[m][n];
    if (ret != -1) return ret;
    ret = 0;
    if (pattern[m] == word[n] || pattern[m] == '?') ret = ret || solve_r(m+1, n+1);
    if (pattern[m] == '*') {
        for (int i = n; i <= word.length(); ++i) {
            ret = ret || solve_r(m+1, i);
        }
        //if (n == word.length()) return ret = 1;
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
        words.clear();
        cin >> pattern;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> word;
            memset(dp, -1, sizeof(dp));
            int ans = solve_r(0, 0);
            if (ans) words.push_back(word);
        }
        sort(words.begin(), words.end());
        for (auto &w : words) cout << w << endl;
    }
}
