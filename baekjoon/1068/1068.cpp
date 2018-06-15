#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
    int leaf = 0;
    if (visited[here]) {
        return;
    }
    visited[here] = true;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            leaf++;
            dfs(there);
        }
    }
    if (leaf == 0) {
        cnt++;
    }
}

void erase_dfs(int here) {
    visited[here] = true;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            erase_dfs(there);
        }
    }
}


int main() {
    int N, root;
    cin>>N;
    adj.resize(N);
    visited.resize(N, false);
    for (int i = 0; i < N; i++) {
        int parent;
        cin>>parent;
        if (parent == -1) {
            root = i;
            continue;     
        }
        adj[parent].push_back(i);
    }
    int rem;
    cin>>rem;
    erase_dfs(rem);
    dfs(root);
    cout<<cnt<<endl;
}