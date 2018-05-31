#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

int V;
vector<vector<pair<int,int>>> adj;

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
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].second;
            int nextDist = cost + adj[here][i].first;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist;
}