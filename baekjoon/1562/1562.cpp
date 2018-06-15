//dp[N][M][S]
#include <cstring>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

typedef long long llong;
const llong MOD = 1000000000LL;

int N;
llong dp[101][10][1<<10];

llong solve_r(int n, int m, int S) {
    if(m < 0 || m > 9) return 0;
    if(n==N) {
        if(S==(1<<10)-1) {
            return 1;
        }
        return 0;
    }
    llong &ret = dp[n][m][S];
    if(ret != -1) {
        return ret;
    }
    ret = solve_r(n+1,m+1,S|(1<<(m+1)))%MOD + solve_r(n+1,m-1,S|(1<<(m-1)))%MOD;
    return ret%MOD;
}

int main() {
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    llong ans = 0;
    for(int i=1;i<10;i++) {
        ans = (ans + solve_r(1,i,(1<<i)))%MOD;
    }
    cout<<ans<<endl;
}