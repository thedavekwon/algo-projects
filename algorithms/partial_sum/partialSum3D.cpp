#include <vector>

using namespace std;

int N, M, K, Q;
int nums[501][501];
int psum[501][501];


void preCalc() {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            psum[i][j] += nums[i][j];                   //itself
            if(i) psum[i][j] += psum[i-1][j];         //not first row
            if(j) psum[i][j] += psum[i][j-1];         //not first column
            if(i && j) psum[i][j] -= psum[i-1][j-1];  //both
        }
    }
}

int gridSum(const vector<vector<int>>& psum, int y1, int x1, int y2, int x2) {
    int ret = psum[y2][x2];
    if(y1) ret -= psum[y1-1][x2];
    if(x1) ret -= psum[y2][x1-1];
    if(y1 && x1) ret += psum[y1-1][x1-1];
    return ret;
}