#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long var;

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

int main() {
    int N, M, K;
    cin>>N>>M>>K;
    vector<var> nums(N);
    for (int i=0;i<N;i++) {
        cin>>nums[i];
    }
    
    int H = (int)ceil(log2(N));
    vector<var> tree(1<<(H+1));
    init(nums,tree,1,0,N-1);
    
    M = M + K;
    int a, b;
    while(M--) {
        cin>>a;
        if (a==1) {
            var c;
            cin>>b>>c;
            b--;
            var diff = c - nums[b];
            nums[b] = c;
            update(tree, 1, 0, N-1, b, diff);
        } else if (a==2) {
            int c;
            cin>>b>>c;
            cout<<sum(tree,1,0,N-1,b-1,c-1)<<endl;
        }
    }
    return 0;
}