//too much memory for dp
#include <cstring>
#include <iostream>

using namespace std;

int N;
int nums[1001];
int dp[1001][1001];

int solve_r(int idx, int val) {
    int &ret = dp[idx][val];
    if (idx == N) return 0;
    if (ret != -1) return ret;
    if (nums[idx] > val) {
        return ret = 1 + solve_r(idx+1,nums[idx]);
    }
    return ret = solve_r(idx+1,val);
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) {
        cin>>nums[i];
    }
    cout<<solve_r(0,0)<<endl;
}