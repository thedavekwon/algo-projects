#include <cstring>
#include <iostream>

using namespace std;

int N;
int nums[1001];
int dp[1001][1001];

int solve_r(int idx, int highest) {
    if (idx == N) return 0;
    int &ret = dp[idx][highest];
    if (ret != -1) return ret;
    ret = 1;
    //cout<<idx<<" "<<highest<<endl;
    for (int i=idx+1; i < N; i++) {
        if (nums[i] > highest) {
            ret = max(ret,1+solve_r(i,nums[i]));            
        } else {
            ret = max(ret,solve_r(i,highest));            
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>nums[i];
    }
    memset(dp,-1,sizeof(dp));
    int MAX = 0;
    for (int i=0;i<N;i++) {
        MAX = max(MAX, solve_r(i,nums[i]));
    }
    cout<<MAX<<endl;
    /*
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
}