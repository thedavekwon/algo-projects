#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 1000000000;

int N;
int dp[101][101];

int solve_r(int idx, int prev) {
    //cout<<idx<<" "<<prev<<endl;
    if (idx == N-1) return 1;
    int &ret = dp[idx][prev];
    if (ret != -1) return ret;
    ret = 0;
    if (prev < 9) {
        ret = (ret + solve_r(idx+1,prev+1))%MOD;
    }
    if (prev > 0) {
        ret = (ret + solve_r(idx+1,prev-1))%MOD;
    }
    return ret;
}

int main() {
    cin>>N;
    memset(dp,-1,sizeof(dp));
    int sum = 0;
    for(int i=1;i<=9;i++) {
        sum = (sum + solve_r(0,i))%MOD;
    }
    cout<<sum<<endl;
}

/*
10
12
21
23
32
34
43
45
54
56
65
67
76
78
87
89
98
*/