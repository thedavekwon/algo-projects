//too slow for edmonds-karp, instead use bipartite matching!
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
    vector<vector<Edge *>> graph;
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

void pprint(int u, int v, int cap) {
    cout<<u<<"->"<<v<<" "<<cap<<endl;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        int N,M;
        cin>>N>>M;
        MaximumFlow mf(N+M+2,0,N+M+1);
        for(int i=0;i<M;i++) {
            int a,b;
            cin>>a>>b;
            for(int j=a; j<=b; j++) {
                //pprint(i+1,N+j,1);
                mf.add_edge(j,N+i+1,1);
            }
        }
        for(int i=1;i<=N;i++) {
            //pprint(mf.source,i,1);
            mf.add_edge_from_source(i,1);
        }
        for(int i=N+1;i<=N+M;i++) {
            //pprint(i,mf.sink,1);
            mf.add_edge_to_sink(i,1);
        }
        cout<<mf.flow()<<endl;
    }
}