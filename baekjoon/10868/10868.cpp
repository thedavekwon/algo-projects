#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long var;

const var INF = 9876543215;

var init(vector<var> &a, vector<var> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = min(init(a, tree, node*2, start, (start+end)/2),
                            init(a, tree, node*2+1, (start+end)/2+1, end));
    }
}

var find_min(vector<var> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    var a = find_min(tree, node*2, start, (start+end)/2, left, right);
    var b = find_min(tree, node*2+1, (start+end)/2+1, end, left, right);
    return min(a,b);
}

int main() {
    int M,N;
    int a,b;
    cin>>M>>N;
    vector<var> nums(M);
    for(int i=0;i<M;i++) {
        cin>>nums[i];
    }
    int h = (int)ceil(log2(M));
    vector<var> tree(1<<(h+1));
    init(nums,tree,1,0,M-1);
    for(int i=0;i<N;i++) {
        cin>>a>>b;
        cout<<find_min(tree,1,0,M-1,a-1,b-1)<<endl;
    }
}