#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int oilPrices[2501];
vector<vector<pair<long,long>>> tmp;
vector<vector<pair<int,int>>> adj;

template <typename T>
vector<T> dijkstra(const vector<vector<pair<T,T>>> &edges, int src) {
    vector<T> dist(N, numeric_limits<T>::max());
    dist[src] = 0;
    priority_queue<pair<T,int>> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        T cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (auto &i : edges[here]) {
            int there = i.first;
            T nextDist = cost + i.second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist;
}


int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> N >> M;
    adj.resize(N);
    tmp.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> oilPrices[i];
    }
    int n, m, c;
    for (int j = 0; j < M; ++j) {
        cin >> n >> m >> c;
        adj[n-1].push_back(pair<int,int>(m-1, c));
        adj[m-1].push_back(pair<int,int>(n-1, c));
    }
    for (int k = 0; k < N; ++k) {
        vector<int> dist = dijkstra(adj, k);
        for (int i = 0; i < dist.size(); ++i) {
            if (i == k && dist[i] == numeric_limits<long long>::max()) continue;
            tmp[k].push_back(pair<long long, long long>(i, (long long) oilPrices[k]*dist[i]));
        }
    }

    auto dist = dijkstra(tmp, 0);
    cout << dist[N-1] << endl;
}