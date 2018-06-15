#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long var;

const var INF = 987654321LL;

struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost;
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    
    int n, source, sink;
    vector<vector<Edge*>> graph;
    vector<bool> check;
    vector<var> distance;
    vector<pair<int,int>> from;
    const var INF = 987654321LL;
    
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        distance.resize(n);
        from.resize(n,make_pair(-1,-1));
    }
    
    void add_edge(int u, int v, int cap, var cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    
    void add_edge_from_source(int v, int cap, var cost) {
        add_edge(source, v, cap, cost);
    }
    
    void add_edge_to_sink(int u, int cap, var cost) {
        add_edge(u, sink, cap, cost);
    }
    
    //shortest path faster algorithm implementation of MCMF
    //difference between bellman ford is that instead of blindly trying all
    //vertices, SPFA maintains a queue of candidate vertices and adds a vertex
    //to the queue only if the vertex is relaxed. It repeats until no more
    //vertices can be relaxed
    bool spfa(int &total_flow, var &total_cost) {
        //initializes vectors
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(),INF);
        fill(from.begin(),from.end(),make_pair(-1,-1));
        queue<int> q;
        distance[source] = 0;
        //start from the source
        q.push(source);
        while(!q.empty()) {
            //pop from the queue to get next vertex for spfa
            int x = q.front(); q.pop();
            //mark the next vertex as not visited
            check[x] = false;
            for(int i=0;i<graph[x].size();i++) {
                //traverse through connected vertexs through edges
                //e = edge, y = destination
                auto e = graph[x][i];
                int y = e->to;
                //if edge's capacity > 0 and 
                if(e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
                    //if vertex relaxed before then add to the queue
                    if (!check[y]) {
                        check[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        if (distance[sink] == INF) {
            return false;
        }
        int x = sink;
        var c = graph[from[x].first][from[x].second]->capacity;
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
        total_flow += c;
        total_cost += c*distance[sink];
        return true;
    }
    
    pair<int,int> flow() {
        int total_flow = 0;
        var total_cost = 0;
        while (spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};

void pprint(int from, int to, var cost) {
    cout<<from<<"->"<<to<<" "<<cost<<endl;
}

int inNode(int idx) {
    return 2*idx;
}

int outNode(int idx) {
    return 2*idx + 1;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>> C(n,vector<int>());
    for(int i=0;i<n;i++) {
        C[i].resize(n-i);
        for(int j=0;j<n-i;j++) {
            cin>>C[i][j];
        }
    }
    MCMF mcmf(2*n+3,0,2*n+2);
    for(int i=1;i<=n+1;i++) {
        mcmf.add_edge(inNode(0),outNode(i),C[0][i],0);
    }
    mcmf.add_edge_from_source(inNode(1),k,0);
    mcmf.add_edge_to_sink(outNode(n),k,0);
    for(int i=1;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            mcmf.add_edge(outNode(i+1),inNode(i+j+1),1,C[i][j]);
        }
    }
    cout<<mcmf.flow().second<<endl;
}