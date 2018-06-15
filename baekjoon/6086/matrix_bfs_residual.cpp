#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int n, source, sink;
int from[1000];
int capacity[1000][1000];
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

//it is basically same with dfs but instead of using dfs record all the route 
//to the from and then subtract capacity by minimum flow in the route.
//and then continue this until all node are visited.
int bfs() {
    memset(check,false,sizeof(check));
    queue<int> q;
    q.push(source);
    //indicate source as -1
    from[source] = -1;
    check[source] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=1;i<=n;i++) {
            if(capacity[x][i] && !check[i]) {
                q.push(i);
                from[i] = x;
                check[i] = true;
            }
        }
    }
    if(!check[sink]) return 0;
    int c = capacity[from[sink]][sink];
    int x = sink;
    while(from[x] != -1) {
        if(c > capacity[from[x]][x]) {
            c = capacity[from[x]][x];
        }
        x = from[x];
    }
    x = sink;
    while(from[x] != -1) {
        capacity[from[x]][x] = capacity[from[x]][x] - c;
        capacity[x][from[x]] = capacity[x][from[x]] + c;
        x = from[x];
    }
    return c;
}

//it flows certain large amount continuously from the source
//to sink until all the capacity is taken. But uses bfs instead
int flow() {
    n = h.size();
    int ans = 0;
    while(true) {
        memset(check,false,sizeof(check));
        int f = bfs();
        if(f==0) break;
        ans = ans + f;
        //cout<<ans<<endl;
    }
    return ans;
}

int main() {
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        capacity[u][v] = capacity[u][v] + f;
        capacity[v][u] = capacity[v][u] + f;
    }
    source = node("A");
    sink = node("Z");
    cout<<flow()<<endl;
}