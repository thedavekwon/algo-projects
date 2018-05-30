#define    forall(i, a, b)    for(int i = a; i < b; i++)

#include <iostream>
#include <vector>

using namespace std;

int count_pairs(const vector<vector<int>> &friends, vector<int> available, int idx);

int main() {
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int N, M;
        scanf("%d %d", &N, &M);
        vector<vector<int>> friends(N, vector<int>(N, 0));
        for (int i = 0; i< M; i++) {
            int m, n;
            scanf("%d %d", &m, &n);
            friends[m][n] = 1;
            friends[n][m] = 1;
        }
        cout << count_pairs(friends, vector<int>(N, 0), 0) << endl;
    }
}

int count_pairs(const vector<vector<int>> &friends, vector<int> available, int idx) {
    int ret = 0;
    forall(i, idx, available.size()) {
        if (available[i] == 0) {
            forall(j, i+1, available.size()) {
                if (friends[i][j] == 1 && available[i] == 0 && available[j] == 0) {
                    available[i] = 1; available[j] = 1;
                    ret = ret + count_pairs(friends, available, i);
                    available[i] = 0; available[j] = 0;
                }
            }
        }
    }

    int cnt = 0;
    forall(i, 0, available.size()){
        cnt = cnt + available[i];
    }
    if (cnt == available.size()) {
        return 1;
    }
    return ret;
}