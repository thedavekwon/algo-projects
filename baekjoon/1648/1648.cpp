#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int dp[1<<14][14*14];

int solve_r(int S,int idx) {
    if(S==0&&idx==N*M) {
        return 1;
    } else if(idx >= N*M) {
        return 0;
    }
    int &ret = dp[S][idx];
    if(ret != -1) return ret;
    if(S&1) {
        ret = solve_r(S>>1,idx+1);
    } else {
        ret = solve_r((S>>1)|(1<<(M-1)),idx+1);
        if(!(S&2)&&!(idx%M==M-1)) ret = ret + solve_r(S>>2,idx+2);
    }
    ret = ret % 9901;
    return ret;
}

int main() {
    scanf("%d%d",&N,&M);
    memset(dp,-1,sizeof(dp));
    cout<<solve_r(0,0)<<endl;
}