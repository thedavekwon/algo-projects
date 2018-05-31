#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> adj;

vector<int> bfs(int now) {
    vector<bool> discovered(adj.size(),false);
    queue<int> q;
    vector<int> order;
    discovered[now] = true;
    q.push(now);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0;i<adj[here].size();i++) {
            int there = adj[here][i];
            if(!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return order;
}