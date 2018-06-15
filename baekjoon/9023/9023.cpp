#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int INF = 987654321;

string orderx, ordery;

int C,D,d;
int X,Y;
int citiesx[100];
int citiesy[100];
int dp[202][101][101][2][2];

int solve_r(int N,int x, int y, int rx, int ry) {
    
    if(x==X && y==Y) return 0;
    if(N >= X+Y) return INF;
    int &ret = dp[N][x][y][rx][ry];
    if(ret != -1) return ret;
    ret = INF;
    if(x<X && y<Y) {
        if(citiesx[x] == citiesy[y]) {
            ret = min(ret,solve_r(N+1,x+1,y+1,0,0)+C);
        } else {
            ret = min(ret,solve_r(N+1,x+1,y+1,0,0)+2*C);
        }
    }
    
    if(x<X) {
        if(ry == 0) {
            ret = min(ret,solve_r(N+1,x+1,y,0,1)+C+D+d);
        } else {
            ret = min(ret,solve_r(N+1,x+1,y,0,1)+C+d);
        }
    }
    
    if(y<Y) {
        if(rx == 0) {
            ret = min(ret,solve_r(N+1,x,y+1,1,0)+C+D+d);
        } else {
            ret = min(ret,solve_r(N+1,x,y+1,1,0)+C+d);
        }
    }
    
    if(rx == 0 && ry == 0) {
        ret = min(ret,solve_r(N+1,x,y,1,1)+D*2+d*2);
    } else if(rx==0||ry==0) {
        ret = min(ret,solve_r(N+1,x,y,1,1)+D+d*2);
    } else {
        ret = min(ret,solve_r(N+1,x,y,1,1)+d*2);
    }
    //cout<<N<<" "<<x<<" "<<y<<" "<<rx<<" "<<ry<<" "<<ret<<endl;
    return ret;
}
int main() {
    int tc;
    scanf("%d\n",&tc);
    while(tc--) {
        scanf("%d%d%d\n",&C,&D,&d);
        getline(cin,orderx);
        getline(cin,ordery);
        int idx=0;
        for(int i=0;i<orderx.size();i++) {
            if(orderx[i] == '0') break;
            if(orderx[i] != ' ') citiesx[idx++] = orderx[i]-'0';
        }
        X = idx;
        idx = 0;
        for(int i=0;i<ordery.size();i++) {
            if(ordery[i] == '0') break;
            if(ordery[i] != ' ') citiesy[idx++] = ordery[i]-'0';
        }
        Y = idx;
        memset(dp,-1,sizeof(dp));
        //cout<<C<<" "<<D<<" "<<d<<endl;
        cout<<solve_r(0,0,0,0,0)<<endl;
    }
}