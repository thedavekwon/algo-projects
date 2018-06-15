#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge * rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    
    int n, source, sink;
    vector<vector<Edge*>> graph;
    
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    
    void add_Edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    
    int bfs() {
        vector<bool> check(n,false);
        vector<pair<int,int>> from(n,make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while(!q.empty()) {
            int here = q.front();q.pop();
            for(int there = 0;there<graph[here].size();there++) {
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
    int N, M;
    scanf("%d%d\n",&N,&M);
    MaximumFlow mf(N+M+2,0,N+M+1);
    for(int i=1;i<=N;i++) {
        mf.add_Edge(0,i,1);
        //cout<<0<<"->"<<i<<endl;
    }
    for(int i=N+1;i<=N+M;i++) {
        mf.add_Edge(i,N+M+1,1);
        //cout<<i<<"->"<<N+M+1<<endl;
    }
    for(int i=1;i<=N;i++) {
        int d;
        scanf("%d",&d);
        for(int j=0;j<d;j++) {
            int job;
            scanf("%d",&job);
            mf.add_Edge(i,job+N,1);
            //cout<<i<<"->"<<job+N<<endl;
        }
    }
    cout << mf.flow() << endl;
}