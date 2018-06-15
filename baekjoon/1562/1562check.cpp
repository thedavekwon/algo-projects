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
//vector<int> answer;

llong solve_r(int n, int m, int S) {
    //cout<<n<<"-"<<m<<"-"<<bitset<10>(S).to_string()<<endl;
    if(n==0) {
        if(S==(1<<m)&&m==0) {
            //answer.push_back(n);
            //answer.push_back(m);
            //answer.push_back(S);
            return 1;
        }
        return 0;
    }
    llong &ret = dp[n][m][S];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(m+1 < 10) ret = ret + (solve_r(n-1,m+1,S) + solve_r(n-1,m+1,S^(1<<(m+1))))%MOD;
    if(m-1 >= 0) ret = ret + (solve_r(n-1,m-1,S) + solve_r(n-1,m-1,S^(1<<(m-1))))%MOD;
    return ret;
}

int main() {
    llong final_answer = 0;
    for(int N=1;N<=40;N++) {
        memset(dp,-1,sizeof(dp));
        llong ans = 0;
        for(int i=1;i<10;i++) {
            ans = ans + solve_r(N,i,(1<<10)-1);
        }
        final_answer = (final_answer + ans);
        cout<<ans<<endl;
    }
    cout<<final_answer<<endl;
}