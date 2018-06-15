#include <cstring>
#include <iostream>

using namespace std;

const int inf = 999999;
const int MAX_V = 101;

int V;
int adj[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V];

void allPairShortestPath1() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
            } else {
                C[0][i][j] = 0;
            }
        }
    }
    
    for (int k = 1; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                C[k][i][j] = min(C[k-1][i][j], C[k-1][i][k] + C[k-1][k][j]);
            }
        }
    }
}

void floyd() {
    for (int i = 0; i < V; i++) {
        adj[i][i] = 0;
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }    
    }
}

int main() {
    int N, M;
    cin>>N>>M;
    V = N;
    memset(adj,inf,sizeof(adj));
    //memset(C,0,sizeof(C));
    for (int i = 0; i < M; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1][b-1] = min(adj[a-1][b-1],c);
    }
    /*
    allPairShortestPath1();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<C[V-1][i][j]<<" ";
        }
        cout<<endl;
    }
    */
    floyd();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}