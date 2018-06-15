//when source and sink are not defined so that we need to connect all the 
//cities to both source and sink

//forgot to consider two group traveling the graph. so the capcaity from source
//to start should be two and end to sink should be two. 
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
    
    //shortest path faster algorithm implementation of MCMF
    //difference between bellman ford is that instead of blindly trying all
    //vertices, SPFA maintains a queue of candidate vertices and adds a vertex
    //to the queue only if the vertex is relaxed. It repeats until no more
    //vertices can be relaxed
    bool spfa(int &total_flow, int &total_cost) {
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

int inNode(int idx) {
    return idx*2;
}

int outNode(int idx) {
    return idx*2 + 1;    
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        int N,M;
        //N: the number of intersections
        //M: the number of roads
        scanf("%d%d",&N,&M);
        //0~2N-1 each vertexs
        //2N     source
        //2N+1   sink
        MCMF mcmf(2*N+4,2*N+2,2*N+3);
        //connect intersection with each node
        for(int i=0;i<M;i++) {
            int from, to;
            scanf("%d%d",&from,&to);
            //cout<<outNode(from-1)<<"->"<<inNode(to-1)<<endl;
            mcmf.add_edge(outNode(from-1),inNode(to-1),1,0);
        }
        //because no redudant intersection for two tourist we need to divide
        //into in and out vertex for each vertex. And then we assgin cost as -1
        //so that we can find the most costly maximum flow.
        for(int i=0;i<N;i++) {
            //cout<<outNode(i)<<"->"<<inNode(i)<<endl;
            mcmf.add_edge(inNode(i),outNode(i),1,-1);
            mcmf.add_edge(2*N,inNode(i),1,0);
            mcmf.add_edge(outNode(i),2*N+1,1,0);
        }
        mcmf.add_edge_from_source(2*N,2,0);
        mcmf.add_edge_to_sink(2*N+1,2,0);
        cout<<-mcmf.flow().second<<endl;
    }
    return 0;
}