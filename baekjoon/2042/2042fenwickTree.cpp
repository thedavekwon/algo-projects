#include <iostream>
#include <vector>

using namespace std;

typedef long long var;

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
        tree[i] = tree[i] + diff;
        i = i + (i & -i);
    }
}

void init(vector<var> &nums, vector<var> &tree, int n) {
    for (int i=1; i<=n; i++) {
        update(tree,i,nums[i]);
    }
}

int main() {
    int N, M, K;
    cin>>N>>M>>K;
    vector<var> tree(N+1);
    vector<var> nums(N+1);
    
    for (int i=1;i<=N;i++) {
        cin>>nums[i];
    }
    
    init(nums,tree,N);
    M = M + K;
    int a, b;
    while(M--) {
        cin>>a;
        if (a==1) {
            var c;
            cin>>b>>c;
            var diff = c - nums[b];
            nums[b] = c;
            update(tree, b, diff);
        } else if (a==2) {
            int c;
            cin>>b>>c;
            cout<<sum(tree,c)-sum(tree,b-1)<<endl;
        }
    }
    return 0;
}