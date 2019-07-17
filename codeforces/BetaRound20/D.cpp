#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

const int N = 1001;
int parent[N];
int size[N];

vector<pair<int, int>> build;
vector<pair<int, int>> close;

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
    ifstream in("./D.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) == find_set(b)) {
            close.emplace_back(a, b);
        } else {
            union_sets(a, b);
        }
    }
    
    for (int i = 2; i <= n; i ++) {
        if (find_set(i) != find_set(1)) {
            union_sets(1, i);
            build.emplace_back(1, i);
        }
    }
    
    cout << close.size() << endl;
    for (int i = 0; i < close.size(); i++) {
        cout << close[i].first << " " << close[i].second <<
            " " << build[i].first << " " << build[i].second << endl;
    }
}