#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
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
    
    void add_Edge(int u, int v, int cap) {
        Edge *ori = new Edge(v, cap);
        Edge *rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    
    int bfs() {
        vector<bool> check(n,false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while(!q.empty()) {
            int here = q.front(); q.pop();
            for(int there = 0; there < graph[here].size(); there++) {
                if(graph[here][there]->capacity && !check[graph[here][there]->to]) {
                    q.push(graph[here][there]->to);
                    check[graph[here][there]->to] = true;
                    from[graph[here][there]->to] = make_pair(here,there);
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
        while(true) {
            int f = bfs();
            if(f==0) break;
            ans = ans + f;
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    MaximumFlow mf(n+m+2,0,n+m+1);
    for(int i=1;i<=n;i++) {
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++) {
            int work;
            cin>>work;
            mf.add_Edge(i,work+n,1);
        }
    }
    for(int i=1;i<=n;i++) {
        mf.add_Edge(0,i,2);
    }
    for(int i=n+1;i<=n+m;i++) {
        mf.add_Edge(i,n+m+1,1);
    }
    cout<<mf.flow()<<endl;
}