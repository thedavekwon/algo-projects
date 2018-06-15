#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

const int INF = 987654321;

int V;
vector<unordered_set<int>> adj;

vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (auto &next : adj[here]) {
            int nextDist = cost + 1;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    return dist;
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    V = N;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        vector<int> tmp(K);
        for (int i = 0; i < K; i++) {
            cin >> tmp[i];
        }
        for (int i = 0; i < K; i++) {
            for (int j = i + 1; j < K; j++) {
                adj[tmp[i]-1].insert(tmp[j]-1);
                adj[tmp[j]-1].insert(tmp[i]-1);
            }
        }
    }
    vector<int> dist = dijkstra(0);
    
    for (auto i : dist) {
        cout<< i << " ";
    }
    cout<<endl;
    
    cout<<dist[N-1]+1<<endl;
}