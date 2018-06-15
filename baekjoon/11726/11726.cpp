#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 10007;

int N;
int dp[1001];

int solve_r(int idx) {
    if (idx == N) return 1;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    ret = 0;
    ret = (ret + solve_r(idx+1))%MOD;
    if (idx < N-1) {
        ret = (ret + solve_r(idx+2))%MOD;
    }
    return ret;
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    cout<<solve_r(0)<<endl;
}