#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[500005];
int color[500005];
int cnt[500005];

int dfs(int idx, int c) {
    color[idx] = c;
    cnt[c]++;
    for (int i = 0; i < graph[idx].size(); i++) {
        if (!color[graph[idx][i]]) {
            dfs(graph[idx][i], c);
        }
    }
}

int main() {
    // ifstream in("./C.input");
    // cin.rdbuf(in.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int t;
        int prev;
        for (int j = 0; j < k; j++) {
            cin >> t;
            if (j) {
                graph[prev-1].push_back(t-1);
                graph[t-1].push_back(prev-1);
            }
            prev = t;
        }
    }
    
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            dfs(i, c++);
        }
        cout << cnt[color[i]] << endl;
    }
    return 0;
}