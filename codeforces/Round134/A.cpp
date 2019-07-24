#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1001*1001;
int parent[N];
int size[N];
int c[N];

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

int index(pair<int, int> &p) {
    return p.first*1000 + p.second;
}

int main() {
    ifstream in("./A.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        make_set(x*1000+y);
        points.emplace_back(x, y);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (points[i].first == points[j].first || points[i].second == points[j].second) {
                union_sets(index(points[i]), index(points[j]));
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < points.size(); i++) {
        if (c[find_set(index(points[i]))] == 0) {
            c[find_set(index(points[i]))]++;
            cnt++;
        }
    }
    cout << cnt-1 << endl;
}