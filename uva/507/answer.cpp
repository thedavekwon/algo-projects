#include <iostream>
#include <fstream>

using namespace std;

int s;
int road[20001];

pair<int,int> solve_r() {
    int start = 0, tmp = 0, end  = 0;
    int sum = 0, ans = 0;
    for (int i =1; i < s; i++) {
        sum = sum + road[i-1];
        // 1) When sum is bigger than current max
        // 2) When sum is same but longer road
        if (sum > ans || (sum == ans && i - tmp > end - start)) {
            ans = sum;
            end = i;
            start = tmp;
        }
        if (sum < 0) {
            sum = 0;
            tmp = i;
        }
    }
    cout << ans << endl;
    return {start, end};
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int route = 0;
    int tc;
    cin >> tc;

    while(tc--) {
        route++;
        cin >> s;
        for (int i = 0; i < s-1; ++i) {
            cin >> road[i];
        }
        auto ans = solve_r();
        if (ans.first >= ans.second) cout << "Route " << route << " has no nice parts" << endl;
        else cout << "The nicest part of route " << route << " is between stops " <<
                  ans.first+1 << " and " << ans.second+1 << endl;
        }
}