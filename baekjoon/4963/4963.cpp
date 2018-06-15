#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dy[8] = {0,-1,-1,-1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0,-1,-1,-1, 0, 1};

void dfs(vector<vector<int>> &map, const vector<vector<int>> &board, int iidx, int jidx) {
    map[iidx][jidx]++;
    for(int i=0;i<8;i++) {
        int y = iidx+dy[i];
        int x = jidx+dx[i];
        if(y >= 0 && y < m && x>=0 && x < n) {
            if(!map[y][x] && board[y][x] == 1) {
                dfs(map,board,y,x);                
            }
        }
    }
}

int main() {
    while(true) {
        cin>>n>>m;
        if(n==0 && m==0) break;
        int cnt = 0;
        vector<vector<int>> board(m,vector<int>(n,0));
        vector<vector<int>> map(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>board[i][j];
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!map[i][j] && board[i][j]==1) {
                    dfs(map,board,i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}