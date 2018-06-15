#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;



int l, sy, sx, ey, ex;

int dy[8] = {2, 1,-1,-2,-2,-1, 1, 2};
int dx[8] = {1, 2, 2, 1,-1,-2,-2,-1};
int dp[301][301];

int solve_r(int y, int x) {
    auto mycmp = [] (const tuple<int,int,int> &t1, tuple<int,int,int> &t2) {
        return get<2>(t1) > get<2>(t2);
    };
    int ty,tx,cnt;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(mycmp)> q;
    q.push(make_tuple(y,x,0));
    memset(dp,0,sizeof(dp));
    while(true) {
        tie(ty,tx,cnt) = q.top();
        cout<<ty<<","<<tx<<" "<<cnt<<endl;
        q.pop();
        if(ty == ey && tx == ex) {
            break;
        }
        for(int i=0;i<8;i++) {
            int cy = dy[i] + ty;
            int cx = dx[i] + tx;
            if(cy < 0 || cy > l || cx < 0 || cx > l) continue;
            if(dp[cy][cx]) continue;
            q.push(make_tuple(cy,cx,cnt+1));
            dp[cy][cx]++;
        }
    }
    return cnt;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>l>>sy>>sx>>ey>>ex;
        cout<<solve_r(sy,sx)<<endl;
    }
}