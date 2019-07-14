#include <iostream>
#include <fstream>

using namespace std;

void visit(vector<int> &visited, const vector<int> &left, const vector<int> &right, int &idx, int &cnt,const int &m);

int main() {
    ifstream in("./E.input");
    cin.rdbuf(in.rdbuf());

    int n, m;
    cin >> n >> m;

    vector<int> lefts(n);
    vector<int> rights(n);
    int min_left = 987654321;
    int max_right = -1;
    

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        lefts[i] = l;
        rights[i] = r;
        
        min_left = min(min_left, l);
        max_right = max(max_right, r);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l < min_left || r > max_right) {
            cout << -1 << endl;
            continue;
        }
        vector<int> visited(max_right, 0);
        for (int i = l; i <= r; i++) {
            visited[i] = 1;
        }
        visit(visited, -1, 0, m);
    }
}

bool check(vector<int> &visited) {
    for (int i = 0; i < visited.size(); i++) {
        if (visisted[i] == 1) return false;
    }
    return true;
}

void mark(vector<int> &visited, const int l, const int r, bool reverse) {
    for (int i = l; i <= r; i++) {
        if (visited[i] == 0) continue;
        if (reverse) visited[i] = 1;
        else visited[i] = 2;
    }
    return;
}

void visit(vector<int> &visited, const vector<int> &left, const vector<int> &right, int &idx, int &cnt,const int &m) {
    if (check(visited)) return cnt;
    if (idx == i)
    int ret = 0;
    for (int i = idx+1; i < m, i++) {
        mark(visited, left[i], right[i], false);
        ret = min(ret, visit(visited, left, right, i, cnt+1, m))
        mark(visited, left[i], right[i], true);
    }
    return ret;
}