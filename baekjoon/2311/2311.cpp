#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost;
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;
    vector<pair<int,int>> from;
    int inf = 987654321;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, int cost) {
        add_edge(source, v, cap, cost);
    }
    void add_edge_to_sink(int u, int cap, int cost) {
        add_edge(u, sink, cap, cost);
    }
    bool spfa(int &total_flow, int &total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            check[x] = false;
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i];
                int y = e->to;
                if (e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
                    if (!check[y]) {
                        q.push(y);
                        check[y] = true;
                    }
                }
            }
        }
        if (distance[sink] == inf) {
            return false;
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
        total_flow += c;
        total_cost += c*distance[sink];
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        while (spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};

int main() {
    int N,M;
    int A,B,C;
    cin>>N>>M;
    MCMF mcmf(N+2,0,N+1);
    for(int i=0;i<M;i++) {
        cin>>A>>B>>C;
        mcmf.add_edge(A,B,1,C);
        mcmf.add_edge(B,A,1,C);
    }
    mcmf.add_edge_from_source(1,2,0);
    mcmf.add_edge_to_sink(N,2,0);
    cout<<mcmf.flow().second<<endl;
}