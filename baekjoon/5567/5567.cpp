#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt;
vector<vector<int>> adj;

void bfs(int now) {
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    vector<int> depth(adj.size(), 0);
    discovered[now] = true;
    q.push(now);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if (depth[here] >= 2) {
                continue;
            }
            if (!discovered[there]) {
                q.push(there);
                cnt++;
                depth[there] = depth[here] + 1;
                discovered[there] = true;
            }
        }
    }
    /*
    for(int i=0;i<adj.size();i++) {
        cout<<discovered[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<adj.size();i++) {
        cout<<depth[i]<<" ";
    }
    cout<<endl;
    */
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i< M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bfs(0);
    cout<<cnt<<endl;
}