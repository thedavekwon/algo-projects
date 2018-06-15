#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, source, sink;
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

//its a simple dfs that has two parameter x=source and
//c=capacity. After this, it does dfs from source until
//it reaches to the sink. and then find the minimum 
//capacity from sink to the source. and then add and 
//subtract from it from the capacity matrix.
//it returns 0 when all the capacity from source to its
//children is less than 0, which means already flowed before.
int dfs(int x, int c) {
    if(check[x]) return 0;
    check[x] = true;
    if(x==sink) return c;
    for(int i=1;i<=n;i++) {
        if(capacity[x][i]>0) {
            int f = dfs(i,min(c,capacity[x][i]));
            if(f) {
                capacity[x][i] = capacity[x][i] - f;
                capacity[i][x] = capacity[i][x] + f;
                return f;
            }
        }
    }
    return 0;
}

//it flows certain large amount continuously from the source
//to sink until all the capacity is taken.
int flow() {
    n = h.size();
    int ans = 0;
    while(true) {
        memset(check,false,sizeof(check));
        int f = dfs(source,1000000);
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