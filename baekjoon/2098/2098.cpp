#include <bitset>
#include <iostream>

using namespace std;

typedef long long llong;

llong INF = 987654321;
int n, W[17][17];
llong dp[1<<17][17];

llong solve_recursive(int S, int i) {
    //cout<<bitset<17>(S).to_string()<<" "<<i<<endl;
    if (S==(1<<n)-1) return W[i][0];
    llong &ret = dp[S][i];
    if (ret != -1) return ret;
    for(int j=0;j<n;j++) {
        if(W[i][j] && !(S&(1<<j))) {
            ret = min(ret,solve_recursive(S+(1<<j),j)+W[i][j]);
            //cout<<i<<" "<<j<<"  "<<W[i][j]<<endl;
        }
    }
    return ret;
}

llong solve_iterative() {
    dp[1][0] = 0;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                for(int k=0;k<n;k++) {
                    if(k != j && (i&(1<<k)) && W[k][j]) {
                        dp[i][j] = min(dp[i][j],dp[i-(1<<j)][k]+W[k][j]);
                    }    
                }
            }
        }
    }
    llong ans = INF;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[(1<<n)-1][i] + W[i][0]);
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&W[i][j]);
        }
    }
    for(int i=0;i<=(1<<n);i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] = INF;
        }
    }
    //cout<<solve_recursive(0,0)<<endl;
    
    cout<<solve_iterative()<<endl;
}