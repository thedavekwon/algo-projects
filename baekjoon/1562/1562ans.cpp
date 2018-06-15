#include <iostream>

using namespace std;

typedef long long llong;

const llong mod = 1000000000LL;

llong dp[101][10][1<<10];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=9; i++) {
        dp[1][i][1<<i] = 1LL;
    }
    for (int i=1; i<=n-1; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<(1<<10); k++) {
                if (dp[i][j][k] == 0) {
                    continue;
                }
                if ((k&(1<<j)) == 0) {
                    continue;
                }
                if (j+1 <= 9) {
                    dp[i+1][j+1][k | (1<<(j+1))] += dp[i][j][k];
                    dp[i+1][j+1][k | (1<<(j+1))] %= mod;
                }
                if (j-1 >= 0) {
                    dp[i+1][j-1][k | (1<<(j-1))] += dp[i][j][k];
                    dp[i+1][j-1][k | (1<<(j-1))] %= mod;
                }
            }
        }
    }

    llong ans = 0;
    for (int i=0; i<=9; i++) {
        ans += dp[n][i][(1<<10)-1];
        ans %= mod;
    }
    cout<<ans<<endl;
}