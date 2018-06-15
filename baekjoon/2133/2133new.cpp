#include <iostream>
#include <cstring> 

using namespace std;

//how can we complete the board?

int N, dp[31];

int solve(int n) {
    if(n==0) return 1;
    if(n==2) return 3;
    int &ret = dp[n];
    if(ret != -1) return ret;
    ret = solve(n-2)*4 - solve(n-4);
    return ret;
}

int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<solve(n)<<endl;
}