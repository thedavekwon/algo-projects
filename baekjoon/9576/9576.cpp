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
    
    void add_edge(int u, int v) {
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
    int tc;
    cin>>tc;
    while(tc--) {
        int N,M;
        cin>>N>>M;
        MaximumFlow mf(max(N,M));
        for(int i=0;i<M;i++) {
            int a,b;
            cin>>a>>b;
            for(int j=a; j<=b; j++) {
                mf.add_edge(j-1,i);
            }
        }
        cout<<mf.flow()<<endl;
    }
}
