#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long llong;

int N,K;
int tens[51];
llong dp[1<<15][100];

string num_string[16];
int lengths[16];
int nums[16];

llong gcd(int x, int y) {
    if(y==0) return x;
    return gcd(y,x%y);
}
//S : situation, m : remainder 
llong solve_r(int S, int m) {
    //cout<<bitset<3>(S).to_string()<<"  "<<m<<endl;
    if(S==(1<<N)-1) {
        if(m==0) return 1;
        return 0;
    }
    llong &ret = dp[S][m];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0;i<N;i++) {
        if((S&(1<<i))) continue;
        int next = m * tens[lengths[i]];
        next %= K;
        next += nums[i];
        next %= K;
        ret = ret + solve_r(S|(1<<i),next);
    }
    return ret;
}

int main() {
    string temp;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        cin>>num_string[i];
        lengths[i] = num_string[i].size();
    }
    
    scanf("%d",&K);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<lengths[i];j++) {
            nums[i] = nums[i]*10 + num_string[i][j] - '0';
            nums[i] %= K;
        }
    }
    tens[0] = 1;
    for(int i=1;i<=50;i++) {
        tens[i] = tens[i-1] * 10;
        tens[i] %= K;
    }
    
    llong ans = solve_r(0,0);
    
    //cout<<"ans: "<<ans<<endl;
    
    llong fact = 1;
    for(int i=2;i<=N;i++) {
        fact *= (llong)i;
    }
    llong g = gcd(ans,fact);
    cout<<ans/g<<"/"<<fact/g<<endl;
}