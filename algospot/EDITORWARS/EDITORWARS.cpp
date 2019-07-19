#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct BipartiteUnionFind {
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    int union_sets(int a, int b) {
        if (a == -1 || b == -1) return max(a, b);
        a = find_set(a);
        b = find_set(b);
        if (a == b) return a;
        if (rank[a] > rank[b]) swap(a, b);
        if (rank[a] == rank[b]) rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        return b;
    }
    
    bool dis_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false;
        a = union_sets(a, enemy[b]);
        b = union_sets(b, enemy[a]);
        enemy[a] = b;
        enemy[b] = a;
        return true;
    }
    
    bool ack_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (enemy[a] == b) return false;
        int aa = union_sets(a, b);
        int bb = union_sets(enemy[a], enemy[b]);
        enemy[aa] = bb;
        if (bb != -1) enemy[bb] = aa;
        return true;
    }
};

int maxParty(const BipartiteUnionFind &buf, const int N) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (buf.parent[i] == i) {
            int enemy = buf.enemy[i];
            if (enemy > i) continue;
            int mySize = buf.size[i];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret = ret + max(mySize, enemySize);
        }
    }
    return ret;
}

int main() {
    int C;
    freopen("input.txt","r",stdin);
    scanf("%d\n", &C);
    
    while (C--) {
        int c = 0;
        int M, N;
        scanf("%d %d\n", &N, &M);        
        BipartiteUnionFind buf = BipartiteUnionFind(N);

        for (int i = 0; i < M; i++) {
            char s[3];
            int a, b;
            scanf("%s %d %d\n", s, &a, &b);
            if (s[0] == 'A') {
                if (!buf.ack_sets(a, b)) {
                    if (c == 0) c = i+1;
                }
            } else {
                if (!buf.dis_sets(a, b)) {
                    if (c == 0) c = i+1;
                }
            }
        }
        
        if (c) cout << "CONTRADICTION AT " << c << endl;
        else cout << "MAX PARTY SIZE IS " << maxParty(buf, N) << endl;
    }
}