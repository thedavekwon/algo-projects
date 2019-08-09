#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n): parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};

const int MAX_V=2001;
int V;

double kruskal(vector<vector<pair<int,double>>> &adj, vector<pair<int, int>> &selected) {
    double ret = 0;
    selected.clear();
    vector<pair<double, pair<int, int>>> edges;
    for (int u = 0; u < V; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            double cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    
    sort(edges.begin(), edges.end());
    
    DisjointSet sets(V);
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        
        if (sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;
    
    while(tc--) {
        vector<vector<pair<int, double>>> adj(MAX_V, vector<pair<int,double>>());
        int N, M;
        cin >> N >> M;
        V = N;
        vector<int> x(N, 0);
        vector<int> y(N, 0);
        
        for (int i = 0; i < N; i++) cin >> x[i];
        for (int i = 0; i < N; i++) cin >> y[i];
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double cost = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                adj[i].push_back(make_pair(j, cost));
            }
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 0));
        }
        vector<pair<int, int>> selected;
        cout << setprecision(11) << kruskal(adj, selected) << endl;
    }
}