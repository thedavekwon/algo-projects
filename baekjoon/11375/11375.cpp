#include <iostream>
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
    vector<bool> check;
    
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    
    //add_Edge adds two edges to the graph vector.
    //first edge is (to v with cap)
    //second edge is (to u with cap 0)
    //we need to this because first edge is the reverse(opposite edge) of 
    //second edge. And when we add and subtract the minimum flow later in dfs
    //we need this for solving with residual method. 
    void add_Edge(int u, int v, int cap) {
        Edge *ori = new Edge(v, cap);
        Edge *rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x==sink) return c;
        for (int i=0;i<graph[x].size();i++) {
            if(graph[x][i]->capacity) {
                int nc = graph[x][i]->capacity;
                if(c != 0 && c < nc) nc = c;
                int f = dfs(graph[x][i]->to,nc);
                if(f) {
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;                
                }
            }
        }
        return 0;
    }
    
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(),check.end(),false);
            int f = dfs(source,0);
            if(f == 0) break;
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