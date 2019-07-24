// implementation of the Ford-Fulkerson method that uses BFS for finding augmenting path
// description: every time we find an augmenting path one of the edges becomes saturated
// and the distance from the edge to s will be longer, if it appears later again in an
// augmenting path. And the length of a simple path is bounded by V


//the difference between the dfs and bfs is that we dont need to make check as
//global variable while traversing the graph and we use bfs to traverse the graph

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
    
    //add_Edge adds two edges to the graph vector.
    //first edge is (to v with cap)
    //second edge is (to u with cap 0)
    //we need to this because first edge is the reverse(opposite edge) of 
    //second edge. And when we add and subtract the minimum flow later in dfs
    //we need this for solving with residual method. 
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

int node(string s) {
    if(s[0] >= 'A' && s[0] <= 'Z') {
        return s[0]-'A';
    } else {
        return s[0] - 'a' + 26;
    }
}

int main() {
    int m;
    cin >> m;
    MaximumFlow mf(52,0,'Z'-'A');
    for (int i=0; i<m; i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        mf.add_Edge(u,v,f);
        mf.add_Edge(v,u,f);
    }
    cout << mf.flow() << endl;
}