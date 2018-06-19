#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    while (true) {
        cin >> tc;
        if (tc == 0) break;
        int X, Y, x, y;
        cin >> X >> Y;
        for (int i = 0; i < tc; ++i) {
            cin >> x >> y;
            if (x-X == 0 || y-Y == 0) cout << "divisa" << endl;
            else {
                if (x-X > 0 && y-Y > 0) cout << "NE" << endl;
                else if (x-X > 0 && y-Y < 0) cout << "SE" << endl;
                else if (x-X < 0 && y-Y < 0) cout << "SO" << endl;
                else if (x-X < 0 && y-Y > 0) cout << "NO" << endl;
            }
        }
    }
}