#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 10007;

int N;
int dp[1000][10];

int solve_r(int idx, int prev) {
    if(idx == N-1) return 1;
    int &ret = dp[idx][prev];
    if(ret != -1) return ret;
    ret = 0;
    ret = (ret + solve_r(idx+1,prev))%MOD;
    for(int i=0;i<=9;i++) {
        if(i>prev) {
            ret = (ret + solve_r(idx+1,i))%MOD;
        }
    }
    return ret;    
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    int sum = 0;
    for(int i=0;i<=9;i++) {
        sum = (sum + solve_r(0,i))%MOD;        
    }
    cout<<sum<<endl;
}