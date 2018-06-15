#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    int n;
    int source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x == -1) return true;
        for (int next : graph[x]) {
            if (check[next]) continue;
            check[next] = true;
            if (dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    int flow() {
        int ans = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<pair<int,int>> car;
    vector<pair<int,int>> park;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'C') {
                car.emplace_back(i,j);
            } else if (a[i][j] == 'P') {
                park.emplace_back(i,j);
            }
        }
    }
    if (car.size() > park.size()) {
        printf("-1\n");
        return 0;
    }
    if (car.size() == 0) {
        printf("0\n");
        return 0;
    }
    vector<vector<int>> parking_time(car.size(), vector<int>(park.size()));
    for (int i=0; i<car.size(); i++) {
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        auto start = car[i];
        q.push(start);
        dist[start.first][start.second] = 0;
        while (!q.empty()) {
            auto now = q.front();
            int x = now.first;
            int y = now.second;
            q.pop();
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (a[nx][ny] != 'X' && dist[nx][ny] == -1) {
                        q.push(make_pair(nx,ny));
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
        for (int j=0; j<park.size(); j++) {
            parking_time[i][j] = dist[park[j].first][park[j].second];
        }
    }
    int impossible = n*m+1;
    int ans = n*m+1;
    int l = 1;
    int r = n*m;
    n = car.size();
    m = park.size();
    while (l <= r) {
        int mid = (l+r)/2;
        MaximumFlow mf(max(n,m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (parking_time[i][j] != -1 && parking_time[i][j] <= mid) {
                    mf.add_edge(i,j);
                }
            }
        }
        if (mf.flow() == n) {
            ans = min(ans,mid);
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    if (ans == impossible) ans = -1;
    printf("%d\n",ans);
    return 0;
}