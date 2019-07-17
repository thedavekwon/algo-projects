#include <iostream>
#include <fstream>

using namespace std;

const int N = 500000;
int parent[N] = {0};
int size[N] = {0};

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    ifstream in("./C.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <=n; i++) {
        make_set(i);
    }
    
    while(m--) {
        int k;
        int t, prev;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> t;
            if (i) {
                union_set(t, prev);
            }
            prev = t;
        }
    }
    
    for (int i = 1; i <=n; i++) {
        cout << size[find_set(i)] << endl;
    }
}