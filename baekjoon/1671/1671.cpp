#include <iostream>
#include <vector>

using namespace std;

typedef long long llong;

llong stat[1000][3];

struct MaximumFlow {
    int n;
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
        for(int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) ans++;
        }
        for(int i=0;i<n;i++) {
            fill(check.begin(),check.end(),false);
            if(dfs(i)) ans++;
        }
        return ans;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            scanf("%lld",&stat[i][j]);
        }
    }
    MaximumFlow mf(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(stat[i][0]>=stat[j][0] && stat[i][1]>=stat[j][1] && 
               stat[i][2]>=stat[j][2]) {
                if(stat[i][0]==stat[j][0] && stat[i][1]==stat[j][1] && 
                   stat[i][2]==stat[j][2]) {
                   if(i>=j) continue;       
                }
                   //cout<<i<<"->"<<j<<endl;
                   mf.add_Edge(i,j);
            }
        }
    }
    cout<<n-mf.flow()<<endl;
}