//1 dimensional dp for memory limit

#include <cstring>
#include <iostream>

using namespace std;

int N, K;
int coins[101];
int dp[10001];

int main() {
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d",&coins[i]);
    }    
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<N;i++) {
        for(int j=coins[i];j<K+1;j++) {
            dp[j] = dp[j] + dp[j-coins[i]];            
        }
    }
    cout<<dp[K]<<endl;
}

