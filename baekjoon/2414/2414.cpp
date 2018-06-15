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
    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    vector<vector<int>> row(n,vector<int>(m,0));
    vector<vector<int>> column(n,vector<int>(m,0));
    int rn = 0, cn = 0;
    for(int i=0;i<n;i++) {
        cin>>board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == '*') {
                if(j-1<0 || board[i][j-1] == '.') {
                    row[i][j] = ++rn;
                } else if (board[i][j-1] == '*') {
                    row[i][j] = row[i][j-1];
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if(board[i][j] == '*') {
                if(i-1<0 || board[i-1][j] == '.') {
                    column[i][j] = ++cn;
                } else if(board[i-1][j] == '*') {
                    column[i][j] = column[i-1][j];
                }
            }
        }
    }
    MaximumFlow mf(max(rn,cn));
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            if(row[i][j] && column[i][j]) {
                mf.add_Edge(row[i][j]-1,column[i][j]-1);
            }    
        }
    }
    cout<<mf.flow()<<endl;
}