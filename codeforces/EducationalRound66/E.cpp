// inspired by the solution on blog

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 500 * 1000 + 13;
pair<int, int> p[N];


pair<int, int> intervals[N];
pair<int, int> queries[N];
    
int prec[N];
int ans[N];


pair<int, int> get(int x, int r){
	if (x == -1)
		return make_pair(-1, -1);
	if (intervals[x].second >= r)
		return make_pair(x, 0);
	auto res = get(p[x].first, r);
	if (res.first == -1)
		p[x] = make_pair(-1, -1);
	else
		p[x] = make_pair(res.first, p[x].second + res.second);
	return p[x];
}

int main() {
    ifstream in("./E.input");
    cin.rdbuf(in.rdbuf());

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = make_pair(l, r);
    }
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = make_pair(l, r);
    }
    
    sort(intervals, intervals+n);
    
    // precalculate points that can be reached with the intervals greedly 
    int idx = 0;
    pair<int, int> mx(0, -1);
    for (int i = 0; i < N; i++) {
        while (idx < n && intervals[idx].first == i){
			mx = max(mx, make_pair(intervals[idx].second, idx));
			++idx;
		}
		prec[i] = (mx.first <= i ? -1 : mx.second);
    }
    
    vector<int> perm(m);
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [](int a, int b) {
		return queries[a].second < queries[b].second;
	});
	
	for (int i = 0; i < N; i++) {
	    p[i] = make_pair(prec[intervals[i].second], prec[intervals[i].second] == -1 ? -1 : 1);
	}
	
	for (auto i : perm) {
	    int x = prec[queries[i].first];
	    auto res = get(x, queries[i].second).second;
	    ans[i] = (res == -1 ? -1 : res+1);
	}
	
	for (int i = 0; i < m ; i++) {
	    cout << ans[i] << endl;
	}
}