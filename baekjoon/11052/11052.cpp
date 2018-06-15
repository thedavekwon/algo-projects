#include <cstring>
#include <iostream>

using namespace std;

int N;
int prices[1001];
int dp[1001][1001];

int solve_r(int idx, int left) {
    //cout<<idx<<" "<<left<<endl;
    if (left == 0) return 0;
    int &ret = dp[idx][left];
    if (ret != -1) return ret;
    ret = 0;
    for(int i=0;i<=left;i++) {
        if(left-i*(idx+1) >= 0) {
            ret = max(ret,prices[idx]*i+solve_r(idx+1,left-i*(idx+1)));            
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>prices[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve_r(0,N)<<endl;
}