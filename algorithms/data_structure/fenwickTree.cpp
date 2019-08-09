#include <vector>

using namespace std;

typedef long long var;

// 1-index
var sum(vector<var> &tree, int i) {
    var ans = 0;
    while (i > 0) {
        ans = ans + tree[i];
        i = i - (i & -i);
    }
    return ans;
}

void update(vector<var> &tree, int i, var diff) {
    while (i < tree.size()) {
        tree[i]= tree[i] + diff;
        i = i + (i & -i);
    } 
}

//need to initiate numbers index from 1~n
void init(vector<var> &nums, vector<var>&tree, int n) {
    for(int i=1;i<=n;i++) {
        update(tree,i,nums[i]);
    }
}

// from cp-algorithms
// FenwickTree Sum
// o-index
struct FenwickTree {
    vector<int> bit;
    int n;
    
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }
    
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r+1)) - 1) {
            ret += bit[r];
        }
        return ret;
    }
    
    int sum(int l, int r) {
        return sum(l) - sum(l-1);
    }
    
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx+1)) {
            bit[idx] += delta;
        }
    }
}

// FenwickTree Minimum
struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = 987654321;
    
    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }
    
    FenwickTreeMin(vector<int> a): FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            update(i, a[i]);
        }
    }
    
    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r+1))-1) {
            ret = min(ret, bit[r]);
        }
        return ret;
    }
    
    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx+1)) {
            bit[idx] = min(bit[idx], val);
        }
    }

}

// 2D FenwickTree

struct FenwickTree2D {
    vector<vector<in>> bit;
    
    FenwickTree(int n, int m) {
        for (int i = 0; i < n; i++) {
            bit[i].assign(m, 0);
        }
    }
    
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i&(i+1))-1) {
            for (int j = y; j >= 0; j = (j&(j+1))-1) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
    
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i+1)) {
            for (int j = y; j < m; j= j | (j+1)) {
                bit[i][j] += delta;
            }
        }
    }
}

// range update and point query

void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx) {
        bit[idx] += val;
    }
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r+1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
        ret += bit[idx];
    }
    return ret;
}