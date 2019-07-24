#include <iostream>
#include <fstream>

using namespace std;

const int N = 202;
int parent[N];
int size[N];

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

void union_sets(int a, int b) {
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
    ifstream in("./A.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    bool flag = false;
    int n, m;
    cin >> n >> m;
    int c[n+1] = {0};
    for (int i = 1; i <= n+m; i++) {
        make_set(i);
    }
    
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k) flag = true;
        int prev_t = -1;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            union_sets(i, n+t);
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (c[find_set(i)] == 0) {
            c[find_set(i)]++;
            cnt++;
        }
    }
    
    if (!flag) {
        cout << cnt << endl;
    } else {
        cout << cnt-1 << endl;
    }
}