//www.acmicpc.net/problem/11122

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

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
    vector<int> distance;
    vector<pair<int,int>> from;
    const int INF = 987654321;
    
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        distance.resize(n);
        from.resize(n,make_pair(-1,-1));
    }
    
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
        fill(distance.begin(), distance.end(),INF);
        fill(from.begin(),from.end(),make_pair(-1,-1));
        queue<int> q;
        distance[source] = 0;
        q.push(source);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            check[x] = false;
            for(int i=0;i<graph[x].size();i++) {
                auto e = graph[x][i];
                int y = e->to;
                if(e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
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

void pprint(int from, int to, int cap, int cost) {
    cout<<from<<"->"<<to<<" "<<cap<<" "<<cost<<endl;
}

int main() {
    int tc;
    cin>>tc;
    int C[16][16];
    int D[16][16];
    int O[16][16];
    int officier[20];
    int arrived[20];
    while(tc--) {
        int N,P;
        cin>>N>>P;
        int groups = (N)*(N-1)/2;
        memset(C,0,sizeof(C));
        memset(D,0,sizeof(D));
        memset(O,0,sizeof(O));
        memset(officier,0,sizeof(officier));
        memset(arrived,0,sizeof(arrived));
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                cin>>C[i][j];
            }
        }
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                cin>>D[i][j];
            }
        }
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                cin>>O[i][j];
                for (int k=i; k<j; k++) {
                    officier[k] += O[i][j];
                }
            }
        }
        
        MCMF mcmf(N+groups+2,0,N+groups+1);
        cout<<N+groups+1<<endl;
        int idx = 1;
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                pprint(mcmf.source,idx,D[i][j],0);
                pprint(idx,i+groups+1,D[i][j],-C[i][j]);
                pprint(idx,j+groups+1,D[i][j],0);
                mcmf.add_edge_from_source(idx,D[i][j],0);  
                mcmf.add_edge(idx,i+groups+1,D[i][j],-C[i][j]);
                mcmf.add_edge(idx,j+groups+1,D[i][j],0);
                arrived[j] += D[i][j];
                idx++;
            }
        }
        for(int i=idx;i<N+groups;i++) {
            pprint(i,i+1,P-officier[i-idx-1],0);
            mcmf.add_edge(i,i+1,P-officier[i-idx-1],0);
        }
        for(int i=idx;i<N+groups+1;i++) {
            pprint(i,mcmf.sink,arrived[i-idx],0);
            mcmf.add_edge_to_sink(i,arrived[i-idx],0);
        }
        
        auto ans = mcmf.flow();
        cout<<ans.first<<endl;
        cout<<-ans.second<<endl;
    }
}