# naive method

const int N = 10000;
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

# random indexing method

const int N = 10000;
int parent[N];
int size[N];

void make_set(int v) {
    parent[v] = v;
    index[v] = rand();
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (index[a] < index[b]) {
            swap(a, b);
        }
        parent[b] = a;
    }
}

# problem of painting subarrays

const int N = 10000;
const int L = 10000;
const int M = 10000;
int parent[N];
int size[N];
int ql[M];
int qr[M];
int qc[M];

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

for (int i = 0; i <= L; i++) {
    make_set(i);
}

for (int i = M-1; i >= 0; i--) {
    for (int v = find_set(ql[i]); v <= find_set(qr[i]); v = find_set(v)) {
        answer[v] = c;
        parent[v] = v + 1;
    }
}

# distance to parent
void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = make_pair(a, 1);
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

# storing explicitly in a set list

const int N = 10000;
vector <int> lst[N];
int parent[N];

void make_set(int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lsb[b].size()) {
            swap(a, b);
        }
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lsb[b].pop_back();
            parent[v] = a;
            lst[a].push_back(v);
        }
    }
}

# Bipartite Union

class BipartiteUnionFind {
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    int union_sets(int a, int b) {
        if (a == -1 || v == -1) return max(a, b);
        a = find_set(a);
        b = find_set(b);
        if (a == b) return a;
        if (rank[a] > rank[b]) swap(a, b);
        if (rank[a] == rank[b]) rank[b]++;
        paret[a] = b;
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
}

int maxSize(const BipartiteUnionFind &buf, const int N) {
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