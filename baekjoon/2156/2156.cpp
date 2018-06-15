#include <cstring>
#include <iostream>

using namespace std;

const int negINF = -1987654321;
int N;
int nums[10001];
int dp[10001][2];

int solve_r(int cur, int flag) {
    if (cur >= N) return 0;
    int &ret = dp[cur][flag];
    if (cur == N-1) return ret = nums[N-1];
    if (ret != -1) return ret;
    if (flag==0) {
        ret = max(ret,nums[cur] + solve_r(cur+1,1));
    }
    for (int i=cur+2;i<=N;i++) {
        ret = max(ret,nums[cur] + solve_r(i,0));
    }    
    return ret;    
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) {
        cin>>nums[i];
    }
    int maximum = 0;
    for(int i=0;i<N;i++) {
        maximum = max(maximum,solve_r(i,0));
    }
    cout<<maximum<<endl;
    return 0;
}