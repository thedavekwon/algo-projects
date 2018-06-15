#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long llong;

llong dp[1<<15][100];

llong gcd(llong x, llong y) {
    if(y==0) return x;
    return gcd(y, x%y);
}

int main() {
    int n;
    int k;
    
    cin >> n;
    
    vector<string> num(n);
    vector<int> a(n);
    vector<int> len(n);
    vector<int> ten(51);
    
    for(int i=0;i<n;i++) {
        cin>>num[i];
        len[i] = num[i].size();
    }
    
    cin >> k;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<len[i];j++) {
            a[i] = a[i]*10 + num[i][j] - '0';
            a[i] %= k;
        }
    }
    ten[0] = 1;
    for(int i=1;i<=50;i++) {
        ten[i] = ten[i-1] * 10;
        ten[i] %= k;
    }
    
    dp[0][0] = 1;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<k;j++) {
            for(int l=0;l<n;l++) {
                if((i&(1<<l))==0) {
                    int next = j * ten[len[l]];
                    next %= k;
                    next += a[l];
                    next %= k;
                    dp[i|(1<<l)][next] += dp[i][j];
                }
            }
        }
    }
    llong ans = dp[(1<<n)-1][0];
    llong fact = 1;
    for(int i=2;i<=n;i++) {
        fact *= (llong)i;
    }
    llong g = gcd(ans,fact);
    cout<<ans/g<<"/"<<fact/g<<endl;
}