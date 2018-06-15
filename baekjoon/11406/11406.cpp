#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    
    int n, source, sink;
    vector<vector<Edge*>> graph;
    
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v, cap);
        Edge *rev = new Edge(u, 0);
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
        vector<bool> check(n,false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(int i=0;i<graph[x].size();i++) {
                if(graph[x][i]->capacity && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if(!check[sink]) return 0;
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while(from[x].first != -1) {
            if(c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while(from[x].first != -1) {
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
            if(f == 0) break;
            ans = ans + f;
        }
        return ans;
    }
};

int main() {
    int N,M,book;
    cin>>N>>M;
    MaximumFlow mf(N+M+2,0,N+M+1);
    for(int i=1;i<=N;i++) {
        cin>>book;
        mf.add_edge_to_sink(M+i,book);
    }
    for(int j=1;j<=M;j++) {
        cin>>book;
        mf.add_edge_from_source(j,book);
    }
    for(int j=1;j<=M;j++) {
        for(int i=1;i<=N;i++) {
            cin>>book;
            mf.add_edge(j,M+i,book);
        }
    }
    cout<<mf.flow()<<endl;
}