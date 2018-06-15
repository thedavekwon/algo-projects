#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

const int INF = 987654321;
int nums[50];

bool isPrime(int num) {
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3;i<(int)sqrt(num)+1;i=i+2) {
        if(num%i==0) {
            return false;
        }
    }
    return true;
}

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
        if(x == -1) return true;
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
        for(int i=1;i<n;i++) {
            fill(check.begin(), check.end(), false);
            if(dfs(i)) ans++;
        }
        return ans;
    }
    
    int solve() {
        int ans = flow();
        //cout<<"flow: "<<ans<<endl;
        if(ans == (n-2)) {
            //cout<<"achieved"<<endl;
            return nums[graph[0][0]];
        }
        return INF;
    }
 };

int main() {
    vector<int> answer;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    for(int i=1;i<n;i++) {
        MaximumFlow mf(n);
        if(!isPrime(nums[0]+nums[i])) continue;
        mf.add_Edge(0,i);
        //cout<<0<<"->"<<i<<endl;
        for(int k=1;k<n;k++) {
            for(int j=1;j<n;j++) {
                if(k!=i && j!=i) {
                    if(!isPrime(nums[k]+nums[j])) continue;
                    mf.add_Edge(k,j);
                    //cout<<k<<"->"<<j<<endl;
                }
            }
        }
        int ans = mf.solve();
        if(ans!=INF) {
            answer.push_back(ans);
        }
    }
    if(answer.size()==0) {
        cout<<-1<<endl;
    } else {
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++) {
            if(i ==answer.size()-1) {
                cout<<answer[i]<<endl;
            } else {
                cout<<answer[i]<<" ";            
            }
        }  
    }
}