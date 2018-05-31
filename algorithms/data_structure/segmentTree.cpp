#include <vector>

using namespace std;

typedef long long var;
//a: numbers
//tree: segment tree
//node: node number in segment tree
//start~end: range of sum responsible for node
var init(vector<var> &a, vector<var> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) +
                            init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

void update(vector<var> &tree, int node, int start, int end, int index, var diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}

//NlgN solution for updating range
void update_range(vector<var> &tree, int node, int start, int end, int left, int right, var diff) {
    if (left > end || right < end) return;
    if (start == end) {
        tree[node] = tree[node] + diff;
        return;
    }
    update_range(tree, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, node*2+1, start, (start+end)/2+1, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

//start~end: range of sum responsible for node
//left+right: range of sum to find
var sum(vector<var> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + 
           sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

//need to change init function to use find_min function
var find_min(vector<var> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return min(find_min(tree, node*2, start, (start+end)/2, left, right), 
               find_min(tree, node*2+1, (start+end)/2+1, end, left, right));
}