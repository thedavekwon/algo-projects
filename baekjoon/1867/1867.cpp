//vertex cover problem but since it is bipartite graph due to the Konig's theorm 
//we can solve it with bipartite matching algorithm.
#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
    int n, source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    
    void add_Edge(int u, int v) {
        graph[u].push_back(v);
    }
    
    bool dfs(int x) {
        if(x==-1) return true;
        for(int next : graph[x]) {
            if(check[next]) continue;
            check[next] = true;
            if(dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    
    int flow() {
        int ans = 0;    
        for (int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) {
                ans = ans + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n,K;
    cin>>n>>K;
    MaximumFlow mf(n);
    for(int k=0;k<K;k++) {
        int i,j;
        cin>>i>>j;
        //cout<<i<<","<<j<<endl;
        mf.add_Edge(i-1,j-1);
    }
    cout<<mf.flow()<<endl;
}