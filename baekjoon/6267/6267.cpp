//solve it as matrix problem not a binary number problem.
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

vector<int> convert(int num) {
    vector<int> converted;
    for(int i=0;i<12;i++) {
        converted.push_back(num&1);
        num = num >> 1;
    }
    return converted;
}

int dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int N;
    while(true) {
        cin>>N;
        if(N==0) break;
        vector<vector<int>> a(N),b(N);
        for(int i=0;i<N;i++) {
            int num;
            cin>>num;
            a[i] = convert(num);
        }
        for(int i=0;i<N;i++) {
            int num;
            cin>>num;
            b[i] = convert(num);
        }
        vector<pair<int,int>> one1, one2;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=12;j++) {
                if(a[i-1][j-1] == 1) {
                    one1.emplace_back(i,j);
                }
                if(b[i-1][j-1] == 1) {
                    one2.emplace_back(i,j);
                }
            }
        }
        if(one1.size() != one2.size()) {
            cout<<"Impossible"<<endl;
            continue;
        }
        MCMF mcmf(2*one1.size()+2,0,2*one1.size()+1);
        for(int i=1;i<=one1.size();i++) {
            for(int j=1;j<=one1.size();j++) {
                mcmf.add_edge(i,j+one1.size(),1,dist(one1[i-1],one2[j-1]));
            }
            mcmf.add_edge_from_source(i,1,0);
            mcmf.add_edge_to_sink(one1.size()+i,1,0);
        }
        cout<<mcmf.flow().second<<endl;
    }
}

//
//0~2^11
//010 -> 110
//
//011 -> 010