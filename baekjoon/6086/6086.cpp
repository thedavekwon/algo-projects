#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct Edge {
    int to;
    int capacity;
    Edge *rev;
    Edge(int to, int capacity) : to(to), capacity(capacity) {
    }
};
map<string,int> h;
int node(string s) {
    if (h.count(s) > 0) {
        return h[s];
    } else {
        int cnt = h.size();
        return h[s] = cnt + 1;
    }
}
vector<Edge *> a[1000];
int n;
int source, sink;
void add_edge(int u, int v, int cap) {
    Edge *ori = new Edge(v,cap);
    Edge *rev = new Edge(u,0);
    ori->rev = rev;
    rev->rev = ori;
    a[u].push_back(ori);
    a[v].push_back(rev);
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
        for (int i=0; i<a[x].size(); i++) {
            if (a[x][i]->capacity > 0 && !check[a[x][i]->to]) {
                q.push(a[x][i]->to);
                check[a[x][i]->to] = true;
                from[a[x][i]->to] = make_pair(x,i);
            }
        }
    }
    if (!check[sink]) {
        return 0;
    }
    int x = sink;
    int c = a[from[x].first][from[x].second]->capacity;
    while (from[x].first != -1) {
        if (c > a[from[x].first][from[x].second]->capacity) {
            c = a[from[x].first][from[x].second]->capacity;
        }
        x = from[x].first;
    }
    x = sink;
    while (from[x].first != -1) {
        Edge *e = a[from[x].first][from[x].second];
        e->capacity -= c;
        e->rev->capacity += c;
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
        add_edge(u,v,f);
        add_edge(v,u,f);
    }
    source = node("A");
    sink = node("Z");
    cout << flow() << '\n';
    return 0;
}