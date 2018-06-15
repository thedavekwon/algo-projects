#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long var;

//initialize the segment tree for solving biggest histogram
//1) when leaf node tree[node] is a index of the node
//2) else 1) if nums[tree.leftchild] <= nums[tree.rightchild], tree[node] = tree[leftchild]
//        2) if nums[tree.leftchild] >= nums[tree.rightchild], tree[node] = tree[rightchild]
//   tree[node] is a smaller value of the left and right child
void init(vector<var> &nums, vector<var> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    } else {
        init(nums,tree,node*2,start,(start+end)/2);
        init(nums,tree,node*2+1,(start+end)/2+1,end);
        if (nums[tree[node*2]] <= nums[tree[node*2+1]]) {
            tree[node] = tree[node*2];
        } else {
            tree[node] = tree[node*2+1];
        }
    }
}

//return next smallest
var query(vector<var> &nums, vector<var> &tree, int node, int start, int end, int left, int right) {
    //not in the range
    if (left > end || right < start) {
        return -1;
    }
    //with in range
    if (left <= start && end <= right) {
        return tree[node];
    }
    //m1 = query for left child, m2 = query for right child
    int m1 = query(nums,tree,node*2,start,(start+end)/2,left,right);
    int m2 = query(nums,tree,node*2+1,(start+end)/2+1,end,left,right);
    
    //if m1 does not exist
    if (m1 == -1) {
        return m2;
    //if m2 does not exist
    } else if (m2 == -1) {
        return m1;
    } else {
    //return smaller value of nums[m1] and nums[m2]
        if (nums[m1] <= nums[m2]) {
            return m1;
        } else {
            return m2;
        }
    }
}

//return largest from the index from query
var largest(vector<var> &nums, vector<var> &tree, int start, int end) {
    int n = nums.size();
    int m = query(nums, tree, 1, 0, n-1, start, end);
    var area = (var)(end-start+1)*(var)nums[m];
    
    if (start <= m-1) {
        var temp = largest(nums, tree, start, m-1);
        area = max(area, temp);
    }
    if (end >= m+1) {
        var temp = largest(nums, tree, m+1, end);
        area = max(area, temp);
    }
    return area;
}

int main() {
    int n=1;
    while(true) {
        cin>>n;
        if (n == 0) break;
        vector<var> hist(n);
        for(int i=0;i<n;i++) {
            cin>>hist[i];
        }
        int h = (int)ceil(log2(n));
        vector<var> tree(1<<(h+1));
        init(hist,tree,1,0,n-1);
        cout<<largest(hist,tree,0,n-1)<<endl;
    }
    return 0;
}