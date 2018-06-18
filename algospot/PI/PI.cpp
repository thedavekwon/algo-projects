#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

string num;
int dp[10001];

int lengths[3] = {3, 4, 5};

void pprint() {
    for (int i = 0; i < num.length(); ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int check(int idx, int length) {
    bool ret1 = true;
    bool ret2 = true;
    for (int i = idx+1; i < idx+length; ++i) {
        if (num[idx] != num[i]) {
            ret1 = false;
            break;
        }
    }
    if (ret1) return 1;

    ret1 = true;
    for (int j = idx; j < idx+length-1; ++j) {
        if (num[j+1]-num[j] != 1) {
            ret1 = false;
        }
        if (num[j+1]-num[j] != -1) {
            ret2 = false;
        }
    }
    if (ret1 || ret2) return 2;

    ret1= true;
    for (int k = 0; k < length; ++k) {
        if (k % 2 == 0) {
            if (num[idx+k] != num[idx]) {
                ret1= false;
                break;
            }
        } else {
            if (num[idx+k] != num[idx+1]) {
                ret1 = false;
                break;
            }
        }
    }
    if (ret1) return 4;


    ret1 = true;
    int tmp = num[idx+1]-num[idx];
    for (int l = idx+1; l < idx+length-1; ++l) {
        if (num[l+1]-num[l] != tmp) {
            ret1 = false;
        }
    }
    if (ret1) return 5;

    return 10;
}


int solve_r(int idx) {
    if (idx == num.length()) return 0;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    ret = 987654321;
    for (int i = 0; i < 3; ++i) {
        if (idx + lengths[i] <= num.length()) {
            ret = min(ret, solve_r(idx + lengths[i]) + check(idx, lengths[i]));
        }
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
        cin >> num;
        memset(dp, -1, sizeof(dp));
        cout << solve_r(0) << endl;
    }
}