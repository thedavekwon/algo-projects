#include <iostream>
#include <cstring>

using namespace std;

int N;
long long dp[91][2];

long long solve_r(int idx, int flag) {
    //cout<<idx<<" "<<flag<<endl;
    if (idx == N-1) return 1; 
    long long &ret = dp[idx][flag];
    if (ret != -1) return ret;
    if(flag == 0) {
        ret = solve_r(idx+1,1) + solve_r(idx+1,0);
    } else {
        ret = solve_r(idx+1,0);
    }
    return ret;
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    cout<<solve_r(0,1)<<endl;
}