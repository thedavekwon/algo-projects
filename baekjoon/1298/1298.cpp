#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
    int n, source, sink;
    vector<vector<int>> graph;
    vector<int> pred;
    vector<bool> check;
    
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        pred.resize(n,-1);
        check.resize(n);
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
        for(int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) ans++;
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    MaximumFlow mf(n);
    for(int i=0;i<m;i++) {
        int ppl, nb;
        cin>>ppl>>nb;
        mf.add_Edge(ppl-1,nb-1);
    }
    cout<<mf.flow()<<endl;
}