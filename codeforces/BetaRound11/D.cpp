#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
        }
    }
}