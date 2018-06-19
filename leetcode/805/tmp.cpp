#include <iostream>

using namespace std;

int main() {
    bool dp[30003][16];
    dp[0][0] = 1;
    cout << dp[0][0] << endl;
}