#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
//initially set values to -1
vector<int> discovered;
vector<bool> isCutVertex;

int counter = 0;

int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    
    for(int i=0;i<adj[here].size();i++) {
        int there = edges[here][i];
        if(discovered[there] == -1) {
            children++;
            int subtree = findCutVertex(there,false);
            if(!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret,subtree);
        } else {
            ret = min(ret,discovered[there]);
        }
    }
    if(isRoot)
        isCutVertex[here] = (children>=2);
    return ret;
}