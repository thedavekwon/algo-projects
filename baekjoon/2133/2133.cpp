#include <cstring>
#include <iostream>

using namespace std;

long long dp[31][8];

//before and after situation consideration is important!

long long solve_dp(int N,int i) {
    if(N==0 && i==7) return 1;
    if(N==0) return 0;
    long long &ret = dp[N][i];
    if(ret != -1) return ret;
    if(i==0) {
        ret = solve_dp(N-1,7);
    } else if(i == 1) {
        ret = solve_dp(N-1,6);
    } else if(i == 2) {
        ret = solve_dp(N-1,5);
    } else if(i == 3) {
        ret = solve_dp(N-1,4) + solve_dp(N-1,7);
    } else if(i == 4) {
        ret = solve_dp(N-1,3);
    } else if(i == 5) {
        ret = solve_dp(N-1,2);
    } else if(i == 6) {
        ret = solve_dp(N-1,1) + solve_dp(N-1,7);
    } else if(i == 7) {
        ret = solve_dp(N-1,0) + solve_dp(N-1,3) + solve_dp(N-1,6);
    }
    //cout<<N<<","<<i<<"  "<<ret<<endl;
    return ret;
}

int main() {
    int n;
    
    memset(dp,-1,sizeof(dp));
    dp[0][7] = 1;
    cin>>n;
    cout<<solve_dp(n,7)<<endl;
}
/*
(2,7) -> (1,0) -> (0,7)
      -> (1,3) -> (0,4) + (0,7)
      -> (1,6) -> (0,1) + (0,7)
*/