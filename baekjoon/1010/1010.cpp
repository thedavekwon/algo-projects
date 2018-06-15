#include <cstring>
#include <iostream>

using namespace std;

int N, M, MAX;
int dp[31][31];

int solve_r(int length, int prev) {
    //cout<<length<<" "<<prev<<endl;
    if (length == MAX) return 1;
    int &ret = dp[length][prev];
    if (ret != -1) return ret;
    ret = 0;
    for (int j=prev+1; j<=M; j++) {
        ret = ret + solve_r(length+1,j);
    }
    return ret;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>N>>M;
        MAX = min(N,M);
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        for(int j=1;j<=M;j++) {
            sum = sum + solve_r(1,j);
        }
        cout<<sum<<endl;
    }
}

