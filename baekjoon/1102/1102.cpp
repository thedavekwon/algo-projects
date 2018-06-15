#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 987654321;

int n,p;
string temp;
int cost[16][16];
int dp[(1<<16)];

int solve_recursive(int S) {
    //cout<<bitset<3>(S).to_string()<<endl;
    if(__builtin_popcount(S)>=p) return 0;
    int &ret = dp[S];
    if(ret != -1) return ret;
    ret = INF;
    for(int i=0;i<n;i++) {
        if(S&(1<<i)) {
            for(int j=0;j<n;j++) {
                if((S&(1<<j))==0) {
                    ret = min(ret,solve_recursive(S|(1<<j))+cost[i][j]);
                }
            }    
        }
    }
    return ret;
}

int main() {
    int start = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    cin>>temp;
    for(int i=0;i<n;i++){
        if(temp[i] == 'Y') {
            start = start | (1<<i);
        }
    }
    scanf("%d",&p);
    memset(dp,-1,sizeof(dp));
    //cout<<bitset<17>(start).to_string()<<endl;
    int ans = solve_recursive(start);
    if(ans == INF) ans = -1;
    cout<<ans<<endl;
}