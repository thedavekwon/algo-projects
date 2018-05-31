#include <vector>

using namespace std;

const int INF = 987654321;

int V;
vector<vector<pair<int,int>>> adj;

vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[src] = 0; visited[src] = true;
    while(true) {
        int closest = INF, here;
        for (int i = 0; i < V; i++) {
            if (dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        if (closest == INF) break;
        visited[here] = true;
        for (int i = 0; i < V; i++) {
            int there = adj[here][i].second;
            if (visited[there]) continue;
            int nextDist = dist[here] + adj[here][i].first;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}