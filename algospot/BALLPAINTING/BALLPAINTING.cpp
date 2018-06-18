#include <iostream>
#include <fstream>

using namespace std;

int N;
int dp[3][1001];

double solve_r(int row, int col) {

}

int main() {
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N;
    while (N != 0) {
        cout << solve_r(1, N) << endl;
    }
}