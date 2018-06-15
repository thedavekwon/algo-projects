#include <iostream>

using namespace std;

const int inf = 999999;
const int MAX_V = 21;

int V;
int adj[MAX_V][MAX_V];
int original[MAX_V][MAX_V];

void floyd() {
    for (int i = 0; i < V; i++) {
        adj[i][i] = 0;
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j= 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    cin >> V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int t;
            cin >> t;
            adj[i][j] = t;
            original[i][j] = t;
        }
    }
    floyd();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}