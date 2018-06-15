#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, source, sink;
int capacity[1000][1000];
int flow[1000][1000];
bool check[1000];

//h is like a dictionary to convert node to num
map<string,int> h;

//this function adds a node to dictionary or find the 
//value in the dictionary
int node(string s) {
    if(h.count(s)>0) {
        return h[s];
    } 
    int cnt = h.size();
    return h[s] = cnt + 1;
}

//the difference here is instead of using residual which subtract directly to
//the capacity matrix, there is flow matrix that do the samething but record in
//the seperate flow matrix. capcity-flow is what we use to find the minimum
//flow in the each dfs. Which is basically same with the residual capcaity-f;
int dfs(int x, int c) {
    if(check[x]) return 0;
    check[x] = true;
    if(x==sink) return c;
    for(int i=1;i<=n;i++) {
        if(capacity[x][i] - flow[x][i] > 0) {
            int f = dfs(i,min(c,capacity[x][i]-flow[x][i]));
            if(f) {
                flow[x][i] = flow[x][i] + f;
                flow[i][x] = flow[i][x] - f;
                return f;
            }
        }
    }
    return 0;
}

//same
int flows() {
    n = h.size();
    int ans = 0;
    while (true) {
        memset(check,false,sizeof(check));
        int f = dfs(source, 1000000);
        if (f == 0) break;
        ans += f;
    }
    return ans;
}

//same
int main() {
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        capacity[u][v] += f;
        capacity[v][u] += f;
    }
    source = node("A");
    sink = node("Z");
    cout << flows() << '\n';
    return 0;
}
