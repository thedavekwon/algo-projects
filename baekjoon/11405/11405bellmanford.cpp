#include <iostream>
#include <vector>

using namespace std;

const int inf = 987654321;

struct MCMF {
    //cost variable added to Edge 
    struct Edge {
        int to;
        int capacity;
        int cost;
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    
    //distance vector added to find the minimum cost
    int n, source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;
    vector<pair<int,int>> from;
    
    //initialize
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n,make_pair(-1,-1));
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
    
    //bellmanFord algorithm to find the total_flow and total_flow
    bool bellman(int &total_flow, int &total_cost) {
        //initialize the vectors
        fill(check.begin(),check.end(),false);
        fill(distance.begin(),distance.end(),inf);
        fill(from.begin(),from.end(),make_pair(-1,-1));
        //distance of source is 0 because it starts from itself.
        distance[source] = 0;
        //step: 0~n-2 (relaxation)
        for(int step = 0; step<n-1; step++) {
            //graph[i][j] == each edge exisiting in the graph
            for(int i=0;i<n;i++) {
                for(int j=0;j<graph[i].size();j++) {
                    auto e = graph[i][j];
                    //skip if an edge can not flow bc capcacity of zero.
                    if (e->capacity == 0) continue;
                    //x = u
                    //y = edge.to
                    int x = i;
                    int y = e->to;
                    //distance[x] == inf means x not reached yet by the
                    //bellman ford algorithm
                    if (distance[x] == inf) continue;
                    //when distance[y] not reached(inf), then distance[y] = 
                    //current distance plus cost from the edge;
                    //if distance[y] already reached, then distance[y] is the
                    //smallest cost needed to reach
                    if (distance[y] > distance[x] + e->cost) {
                        distance[y] = distance[x] + e->cost;
                        //record where this edge
                        from[y] = make_pair(i,j);
                    }
                }
            }
        }
        //if sink not reachable from the source
        if(distance[sink] == inf) return false;
        //same as network flow add capacity and subtract capacity to find the
        //maximum flow of the graph
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
        //flow = c
        //cost = flow*cost
        total_flow = total_flow + c;
        total_cost = total_cost + c*distance[sink];
        return true;
    }

    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        while(bellman(total_flow,total_cost));
        return make_pair(total_flow,total_cost);
    }
};

int main() {
    int N,M,cost;
    cin>>N>>M;
    MCMF mcmf((N+M+2),0,N+M+1);
    vector<int> books(N+1);
    for(int i=1;i<=N;i++) {
        cin>>books[i];
    }
    vector<int> bookstore(M+1);
    for(int i=1;i<=M;i++) {
        cin>>bookstore[i];
    }
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            cin>>cost;
            mcmf.add_edge(i,M+j,inf,cost);
        }
    }
    for(int i=1;i<=M;i++) {
        mcmf.add_edge_from_source(i,bookstore[i],0);
    }
    for(int j=1;j<=N;j++) {
        mcmf.add_edge_to_sink(M+j,books[j],0);
    }
    cout<<mcmf.flow().second<<endl;
}