//it uses edmonds-karp algorithm to find out the minimum cut required to stop
//the flow of the graph. Instead of cutting the edge, this problem wants us to 
//cut the edge. Therefore we add an edge in between each vertext with capacity
//1. after that we just basically connect all the vertexs through seraching the
//map!.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
    }
    int bfs() {
        vector<bool> check(n, false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (!check[sink]) {
            return 0;
        }
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first != -1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int in_node(int x, int y, int m) {
    return 2*(x*m+y);
}

int out_node(int x, int y, int m) {
    return in_node(x,y,m)+1;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    for(int i=0;i<n;i++) {
        cin>>board[i];
    }
    int sx,sy,ex,ey;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 'K') {
                sx=i;
                sy=j;
            }
            if (board[i][j] == 'H') {
                ex=i;
                ey=j;
            }
        }
    }
    int INF = 987654321;
    MaximumFlow mf(2*(n*m),out_node(sx,sy,m),in_node(ex,ey,m));
    for(int i = 0; i<n; i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]=='#') continue;
            mf.add_edge(in_node(i,j,m),out_node(i,j,m),1);
            for(int k=0;k<4;k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(0<=nx && nx < n && 0<=ny && ny < m) {
                    if(board[nx][ny] != '#') {
                        mf.add_edge(out_node(i,j,m),in_node(nx,ny,m),INF);
                    }
                }
            }
        }
    }
    int ans = mf.flow();
    if(ans >= INF) {
        ans = -1;
    }
    cout<<ans<<endl;
}