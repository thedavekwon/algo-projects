#include <iostream>
#include <vector>

using namespace std;

int counter;

vector<vector<int>> adj;
vector<int> discovered, finished;

void dfs(int here) {
    discovered[here] = counter++;
    for(int i=0;i<adj.size();i++) {
        int there = adj[here][i];
        if(discovered[there] == -1) {
            //tree-edge
            dfs(there);
        } else if(discovered[here]<discovered[there]) {
            //forward-edge
        } else if(finished[there] == 0) {
            //back-edge
        } else {
            //cross-edge
        }
    }
    finished[here] = 1;
}
