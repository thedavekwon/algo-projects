#include <cstring>
#include <iostream>

using namespace std;

int board[30][30];
int H, M;

int solve_r();

int main() {
    int tc;
    scanf("%d\n", &tc);
    while(tc--) {
        memset(board, 0, sizeof(board));
        scanf("%d %d\n", &H, &M);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < M; j++) {
                char c;
                scanf("%c", &c);
                if (c == '.') board[i][j] = 0;
                if (c == '#') board[i][j] = 1;
            }
            scanf("\n");
        }
        cout << solve_r() << endl;
    }
}

void print_board() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

int solve_r() {
    // print_board();
    int ret = 0;
    bool tobreak = false;
    int i = 0, j = 0;
    for  ( ; i < H; i++) {
        for ( ; j < M; j++) {
            if (board[i][j] == 0) {
                tobreak = true;
                break;
            }
        }
        if (tobreak) break;
        j = 0;
    }
    if (tobreak == false) return 1;

    //case 1 ##
    //        #
    if (i+1 < H && j+1 < M) {
        if (!board[i][j] && !board[i][j+1] && !board[i+1][j+1]) {
            board[i][j] = board[i][j+1] = board[i+1][j+1] = 1;
            ret = ret + solve_r();
            board[i][j] = board[i][j+1] = board[i+1][j+1] = 0;
        }
    }
    //case 2 #
    //      ##
    if (i+1 < H && j-1 >= 0) {
        if(!board[i][j] && !board[i+1][j] && !board[i+1][j-1]) {
            board[i][j] = board[i+1][j] = board[i+1][j-1] = 1;
            ret = ret + solve_r();
            board[i][j] = board[i+1][j] = board[i+1][j-1] = 0;
        }
    }
    //case 3 #
    //       ##
    if (i+1 < H && j+1 < M) {
        if(!board[i][j] && !board[i+1][j] && !board[i+1][j+1]) {
            board[i][j] = board[i+1][j] = board[i+1][j+1] = 1;
            ret = ret + solve_r();
            board[i][j] = board[i+1][j] = board[i+1][j+1] = 0;
        }
    }
    //case 4 ##
    //       #
    if (i+1 < H && j+1 < M) {
        if (!board[i][j] && !board[i][j+1] && !board[i+1][j]) {
            board[i][j] = board[i][j+1] = board[i+1][j] = 1;
            ret = ret + solve_r();
            board[i][j] = board[i][j+1] = board[i+1][j] = 0;
        }
    }
    return ret;
}