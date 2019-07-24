// 1. set the flow of each edge to zero
// 2. look for an augmenting path from s to t.
//    An augmenting path is simple path in the residual graph along the edges
//    whose residual capacity is positive
// 3. We keep on searching for augmenting paths and increasing the flow

#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int V;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
    memset(flow,0,sizeof(flow));
    int totalFlow = 0;
    while(true) {
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty()&&parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for(int there=0; there<V;there++) {
                if(capacity[here][there] - flow[here][there] > 0 &&
                   parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p=sink;p!=source;p=parent[p]) {
            amount = min(capacity[parent[p]][p]-flow[parent[p]][p], amount);
        }
        for(int p=sink;p!=souce;p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;    
}