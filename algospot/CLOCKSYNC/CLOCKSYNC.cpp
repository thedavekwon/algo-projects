#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

double solve_r(int idx, int cnt);
void push(int button);
bool check_done();
void print_clocks();

int clocks[16];
int clockSwitch[10][6] = {
        { 0,1,2,-1, },
        { 3,7,9,11,-1, },
        { 4,10,14,15,-1, },
        { 0,4,5,6,7,-1, },
        { 6,7,8,10,12,-1, },
        { 0,2,14,15,-1, },
        { 3,14,15,-1,},
        { 4,5,7,14,15,-1, },
        { 1,2,3,4,5,-1, },
        { 3,4,5,9,13,-1, }
};

int main() {
    ifstream in("CLOCKSYNC/input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;
    while(tc--) {
        memset(clocks, 0, sizeof(clocks));
        for (int &clock : clocks) {
            cin >> clock;
        }
        int answer = solve_r(0, 0);
        if (answer == 987654321) {
            cout << -1 << endl;
        } else {
            cout << answer <<endl;
        }
    }
}

double solve_r(int idx, int cnt) {
    //print_clocks();
    if (check_done()) return cnt;
    if (idx == 10) return 987654321;
    int ret = 987654321;
    for (int i = 0; i < 4; i++) {
        push(idx);
        cnt++;
        if (i == 3) ret = min(ret, solve_r(idx+1, cnt-4));
        else ret = min(ret, solve_r(idx+1, cnt));

    }
    return ret;
}


void push(int button) {
    for (int i = 0; i < 6; i++) {
        if (clockSwitch[button][i] == -1) break;
        if (clocks[clockSwitch[button][i]] == 12) clocks[clockSwitch[button][i]] = 3;
        else clocks[clockSwitch[button][i]] += 3;
    }
}

bool check_done() {
    for (int clock : clocks) {
        if (clock != 12) return false;
    }
    return true;
}

void print_clocks() {
    for (const int clock: clocks) {
        cout << clock << " ";
    }
    cout << endl;
}