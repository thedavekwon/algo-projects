#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> outdegree,indegree;

void getEulerCircuit(int here, vector<int> &circuit) {
    for(int there = 0;i<adj.size();i++) {
        while(adj[here][there] > 0) {
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(here,circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailorCircuit() {
    vector<int> circuit;
    //Trail
    for(int i=0;i<adj.size();i++) {
        if(outdegree[i] == indegree[i] + 1) {
            getEulerCircuit(i,circuit);
            return circuit;
        }
    }
    for(int i=0;i<adj.size();i++) {
        if(outdegree[i]) {
            getEulerCircuit(i,circuit);
            return circuit;
        }
    }
    return circuit;
}

bool checkEuler() {
    int start=0, end=0;
    for(int i=0;i<adj.size();i++) {
        int delta = outdegree[i] - indegree[i];
        if(delta<-1 || delta > 1) return false;
        if(delta == 1) start++;
        if(delta == -1) end++;
    }
    return (start == 1 && end == 1) || (start == 0 && end == 0);
}