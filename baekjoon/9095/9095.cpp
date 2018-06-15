#include <cstring>
#include <iostream>

using namespace std;

int N;
int dp[12];

int solve_r(int cur) {
    if (cur == N) return 1;
    if (cur > N) return 0;
    int &ret = dp[cur];
    if (ret != -1) return ret;
    ret = solve_r(cur+1) + solve_r(cur+2) + solve_r(cur+3);
    return ret;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>N;
        memset(dp,-1,sizeof(dp));
        cout<<solve_r(0)<<endl;
    }
}