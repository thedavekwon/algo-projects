//should consider path, naively considered only absolute distance of the path
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> car;
vector<pair<int,int>> park;

struct MaximumFlow {
    int n, source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    
    void add_Edge(int u, int v) {
        graph[u].push_back(v);
    }
    
    bool dfs(int x) {
        if(x==-1) return true;
        for(int next : graph[x]) {
            if(check[next]) continue;
            check[next] = true;
            if(dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    
    int flow() {
        int ans = 0;    
        for (int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) {
                ans = ans + 1;
            }
        }
        return ans;
    }
};

/*
int dist(int i1, int j1, int i2, int j2) {
    return abs(i2-i1) + abs(j2-j1);
}
*/

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    for(int i=0;i<n;i++) {
        cin>>board[i];        
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]=='P') park.emplace_back(i,j);
            if(board[i][j]=='C') car.emplace_back(i,j);
        }
    }
    if(car.size()==0) {
        cout<<0<<endl;
        return 0;
    }
    if(car.size()>park.size()) {
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<int>> parking_time(car.size(),vector<int>(park.size()));
    for(int i=0;i<car.size();i++) {
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        auto start = car[i];
        q.push(start);
        dist[start.first][start.second] = 0;
        while(!q.empty()) {
            auto now = q.front(); q.pop();
            int x = now.first;
            int y = now.second;
            //cout<<x<<" "<<y<<endl;
            for(int k=0;k<4;k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(0<=nx && nx <n && 0<=ny && ny<m) {
                    if(board[nx][ny] != 'X' && dist[nx][ny] == -1) {
                        q.push(make_pair(nx,ny));
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
        //for(int i=0;i<n;i++) {
        //    for(int j=0;j<n;j++) {
        //        cout<<dist[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        for(int j=0;j<park.size();j++) {
            parking_time[i][j] = dist[park[j].first][park[j].second];
        }
    }
    int l = 0, r = n*m, mid;
    int impossible = n*m+1;
    int ans = n*m+1;
    n = car.size();
    m = park.size();
    //for(int i=0;i<car.size();i++) {
    //   for(int j=0;j<park.size();j++) {
    //        cout<<parking_time[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    while(l<=r) {
        MaximumFlow mf(max(n,m));
        mid = (l+r)/2;
        for(int i=0;i<car.size();i++) {
            for(int j=0;j<park.size();j++) {
                if(parking_time[i][j] != -1 &&parking_time[i][j] <= mid) {
                    //cout<<i<<","<<j<<endl;
                    mf.add_Edge(i,j);
                }        
            }
        }
        //cout<<l<<' '<<r<<"--->"<<mid<<endl;
        if(mf.flow()==car.size()) {
            ans = min(ans,mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    if(ans==impossible) {
        ans = -1;
    }
    cout<<ans<<endl;
}