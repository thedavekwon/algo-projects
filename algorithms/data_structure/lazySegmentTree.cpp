#include <vector>

using namespace std;

typedef long long ll;

ll init(vector<ll> &nums, vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = nums[start];
    } else {
        return tree[node] = init(nums, tree, node*2, start, (start+end)/2) + 
                            init(nums, tree, node*2+1, (start+end)/2+1, end);
    }
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = tree[node] + (end-start+1)*lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += (end-start+1)*diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range_lazy(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range_lazy(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + 
           sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    
}