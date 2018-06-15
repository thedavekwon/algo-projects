#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int dp[501][501];
int board[501][501];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int solve_r(int y, int x) {
    if (y == N-1 && x == M-1) {
        return 1;
    }
    int &ret = dp[y][x];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < 4; i++) {
        if ((y+dy[i] >= 0 && y+dy[i] < N && x+dx[i] >= 0 && x+dx[i] < M)) {
            if (board[y][x] > board[y+dy[i]][x+dx[i]]) {
                //cout << board[y][x] << "      " << board[y+dy[i]][x+dx[i]] << endl;
                ret = ret + solve_r(y+dy[i], x+dx[i]);
            }
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    memset(board, 99999, sizeof(dp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cout << solve_r(0,0) << endl;
}