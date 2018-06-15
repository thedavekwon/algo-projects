#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow{
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
        //not visited before
        if(x==-1) return true;
        for(int next:graph[x]) {
            //already visited
            if(check[next]) continue;
            check[next] = true;
            if(dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    
    //do dfs each vertex on the left twice
    int flow() {
        int ans = 0;
        for (int i=0;i<n;i++) {
            for(int j=0;j<2;j++) {
                fill(check.begin(),check.end(),false);
                if(dfs(i)) {
                    ans = ans + 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    MaximumFlow mf(max(n,m));
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