#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, source, sink;
map<string,int> h;

//add node to the dictionary(map)
int node(string s) {
    if (h.count(s) > 0) {
        return h[s];
    } else {
        int cnt = h.size();
        return h[s] = cnt + 1;
    }
}

//Data structure of Edge uses Linked list.
struct Edge {
    int to;
    int capacity;
    Edge *rev;
    Edge(int to, int capacity) : to(to), capacity(capacity) {
    }
};

//uses pointer array for memory efficiency 
vector<Edge *> edges[1000];

//a way to add edges to the edge array.
void add_Edge(int u, int v, int cap) {
    Edge *ori = new Edge(v,cap);
    Edge *rev = new Edge(u,0);
    ori->rev = rev;
    rev->rev = ori;
    edges[u].push_back(ori);
    edges[v].push_back(rev);
}


int bfs() {
    vector<bool> check(n+1, false);
    vector<pair<int,int>> from(n+1, make_pair(-1,-1));
    queue<int> q;
    q.push(source);
    check[source] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0;i<edges[x].size();i++) {
            //capacity > 0 and not visited yet
            if(edges[x][i]->capacity > 0 && !check[edges[x][i]->to]) {
                //add to the queue
                q.push(edges[x][i]->to);
                //mark as visited
                check[edges[x][i]->to] = true;
                //add to the from array to record where it came from
                from[edges[x][i]->to] = make_pair(x,i);
            }
        }
    }
    //if sink not reachable from source
    if(!check[sink]) return 0;
    int x = sink;
    //start from the sink
    int c = edges[from[x].first][from[x].second]->capacity;
    //get the minimum flow that it can make with traversing through array
    while (from[x].first != -1) {
        if (c > edges[from[x].first][from[x].second]->capacity) {
            c = edges[from[x].first][from[x].second]->capacity;
        }
        x = from[x].first;
    }
    //subtract the minimum flow calculated from the above
    x = sink;
    //form[x].first != -1 means until x equals to the source
    while (from[x].first != -1) {
        Edge *e = edges[from[x].first][from[x].second];
        e->capacity = e->capacity - c;
        e->rev->capacity = e->rev->capacity + c;
        x = from[x].first;
    }
    return c;
}


int flow() {
    n = h.size();
    int ans = 0;
    while (true) {
        int f = bfs();
        if (f == 0) break;
        ans += f;
    }
    return ans;
}

int main() {
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        add_Edge(u,v,f);
        add_Edge(v,u,f);
    }
    source = node("A");
    sink = node("Z");
    cout << flow() << endl;
}