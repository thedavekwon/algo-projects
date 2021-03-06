//bipartite matching == minimum vertex cover for bipartite graph
#include <iostream>
#include <vector>

using namespace std;

struct MaxmiumFlow {
    int n;
    vector<vector<int>> graph;
    vector<int> pred;
    vector<bool> check;
    
    MaxmiumFlow(int n) : n(n) {
        graph.resize(n);
        pred.resize(n,-1);
        check.resize(n);
    };
    
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    
    bool dfs(int x) {
        if (x == -1) return true;
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

int index(int i, int j, int n) {
    return i*n + j;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        int n,m;
        int cnt=0;
        cin>>n>>m;
        vector<string> board(n);
        for(int i=0;i<n;i++) {
            cin>>board[i];
        }
        MaxmiumFlow mf(n*m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == 'x') continue;
                cnt++;
                if(i>0 && j>0) {
                    if(board[i-1][j-1] == '.') {
                        mf.add_edge(index(i,j,m),index(i-1,j-1,m));
                    }
                }
                if(i>0 && j<m-1) {
                    if(board[i-1][j+1] == '.') {
                        mf.add_edge(index(i,j,m),index(i-1,j+1,m));    
                    }
                }
                if(j<m-1) {
                    if(board[i][j+1] == '.') {
                        mf.add_edge(index(i,j,m),index(i,j+1,m));
                    }
                }
                if(j>0) {
                    if(board[i][j-1] == '.') {
                        mf.add_edge(index(i,j,m),index(i,j-1,m));
                    }
                }
                if(i<n-1 && j<m-1) {
                    if(board[i+1][j+1] == '.') {
                        mf.add_edge(index(i,j,m),index(i+1,j+1,m));    
                    }
                }
                if(i<n-1 && j>0) {
                    if(board[i+1][j-1] == '.') {
                        mf.add_edge(index(i,j,m),index(i+1,j-1,m));    
                    }
                }
            }
        }
        cout<<cnt-mf.flow()/2<<endl;
    }
}