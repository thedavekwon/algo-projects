#include <cstring>
#include <iostream>

using namespace std;

int N;
int nums[501][501];
int dp[501][501];

int solve_r(int h, int idx) {
    if (h == N) return 0;
    int &ret = dp[h][idx];
    if (ret != -1) return ret;
    //cout<<h<<" "<<idx<<"   "<<nums[h][idx]<<endl;
    ret = nums[h][idx];
    ret = max(ret + solve_r(h+1,idx+1), ret + solve_r(h+1,idx));
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0; j<i+1; j++) {
            cin>>nums[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve_r(0,0)<<endl;
    /*
    for(int i=0;i<N;i++) {
        for(int j=0; j<i+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
}