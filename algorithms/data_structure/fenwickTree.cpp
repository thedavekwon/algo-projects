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

