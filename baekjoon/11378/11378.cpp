#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
    int n, k, source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    
    MaximumFlow(int n, int k) : n(n), k(k) {
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
        int cnt = 0;
        for (int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) {
                ans = ans + 1;
            }
        }
        int i=0;
        while (i<n) {
            if(cnt == k) break;
            fill(check.begin(),check.end(),false);
            if(dfs(i)) {
                ans = ans + 1;
                cnt = cnt + 1;
                continue;
            }
            i++;
        }
        return ans;
    }
};

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    MaximumFlow mf(max(n,m),k);
    for(int i=0;i<n;i++) {
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++) {
            int job;
            cin>>job;
            mf.add_Edge(i,job-1);
        }
    }
    cout<<mf.flow()<<endl;
}