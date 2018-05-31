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