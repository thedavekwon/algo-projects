#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Edge{
    int to;
    int capacity;
    Edge *rev;
    Edge(int to, int capacity) : to(to),capacity(capacity) {
    }
};

int n, source, sink;
bool check[1000];
map<string,int> h;
vector<Edge *> edges[1000];

int node(string s) {
    if(h.count(s)) {
        return h[s];
    } else {
        int cnt = h.size();
        return h[s] = cnt + 1;
    }
}

void add_Edge(int u, int v, int cap) {
    Edge *ori = new Edge(v, cap);
    Edge *rev = new Edge(u, 0);
    ori->rev = rev;
    rev->rev = ori;
    edges[u].push_back(ori);
    edges[v].push_back(rev);
}

int dfs(int x, int c) {
    if (check[x]) return 0;
    check[x] = true;
    if (x==sink) return c;
    for(int i=0; i<edges[x].size(); i++) {
        if (edges[x][i]->capacity > 0) {
            //the difference here from matrix_dfs_residual is that we have to 
            //check whether capacity is not 0 plus capcity is smaller than new
            //capcicty. The reason why we have to check capcity is not 0 is that
            //when capcity is 0, it is located a the source. Therefore, we are
            //ignoring the initial value dfs(source,0) by adding c!=0.
            int nc = edges[x][i]->capacity;
            if(c != 0 && c < nc) {
                nc = c;
            }
            int f = dfs(edges[x][i]->to,nc);
            if(f) {
                edges[x][i]->capacity = edges[x][i]->capacity - f;
                edges[x][i]->rev->capacity = edges[x][i]->rev->capacity + f;
                return f;
            }
        }
    }
    return 0;
}

//same with the matrix_dfs_residual. The only difference is mentioned above in 
//the comment.
int flow() {
    n = h.size();
    int ans = 0;
    while(true) {
        memset(check,false,sizeof(check));
        int f = dfs(source, 0);
        if (f==0) break;
        ans = ans + f;
    }
    return ans;
}
int main() {
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int f;
        string us, vs;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        add_Edge(u,v,f);
        add_Edge(v,u,f);
    }
    source = node("A");
    sink = node("Z");
    cout << flow() <<endl;
}