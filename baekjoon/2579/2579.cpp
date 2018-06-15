#include <cstring>
#include <iostream>

using namespace std;

int negINF = -1*987654321;

int N;
int nums[301];
int dp[301][301];

int solve_r(int cur, int prev) {
    if (cur==N-1) return nums[N-1];
    if (cur==N) return negINF;
    int &ret = dp[cur][prev];
    if (ret != -1) return ret;
    ret = negINF;
    if (cur-prev==1) {
        ret = max(ret,nums[cur] + solve_r(cur+2,cur));    
    } else {
        ret = max(ret,nums[cur] + solve_r(cur+1,cur));
        ret = max(ret,nums[cur] + solve_r(cur+2,cur));
    }
    return ret;
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) {
        cin>>nums[i];
    }
    cout<<max(solve_r(0,0),solve_r(1,1))<<endl;
}