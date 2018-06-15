#include <cstring>
#include <iostream>

using namespace std;

int W[16][16];
char str[20];
int dp[1<<16];

int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&W[i][j]);
        }
    }
    
    scanf("%s",str);
    int start = 0;
    for(int i=n-1;i>=0;i--) {
        start = start * 2;
        if(str[i] == 'Y') start = start + 1;
    }
    
    int p;
    scanf("%d",&p);
    dp[start] = 0;
    for(int i=0;i<(1<<n);i++) {
        if(dp[i] == -1) continue;
        for(int j=0;j<n;j++) {
            //j is on in i
            if(i&(1<<j)) {
                for(int k=0;k<n;k++) {
                    //k is off in i
                    if(!(i&(1<<k))) {
                        if(dp[(i|(1<<k))] == -1 || dp[(i|(1<<k))] > dp[i] + W[j][k]) {
                            dp[(i|(1<<k))] = dp[i] + W[j][k];
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<(1<<n);i++) {
        if(dp[i] == -1) continue;
        int cnt = __builtin_popcount(i);
        if(cnt >=p) {
            if(ans == -1 || ans > dp[i]) {
                ans = dp[i];
            }
        }
    }
    cout<<ans<<endl;
}