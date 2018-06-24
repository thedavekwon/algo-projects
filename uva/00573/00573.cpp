#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string solve(int h, int u, int d, int f) {
    double cur = 0;
    bool success = false;
    int day = 0;
    for (int i = 1; i < 1000; ++i) {
        cur = cur + u * max(1-(static_cast<double>(f*(i-1))/100), 0.0);
        if (cur > h) {
            day = i;
            success = true;
            break;
        }
        cur = cur - d;
        if (cur < 0) {
            day = i;
            break;
        }
    }
    if (success) {
        return "success on day " + to_string(day);
    } else {
        return "failure on day " + to_string(day);
    }
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int h, u, d, f;
    while (true) {
        cin >> h >> u >> d >> f;
        if (h == 0) break;
        cout << solve(h, u, d, f) << endl;
    }
}