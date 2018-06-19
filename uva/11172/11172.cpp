#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        double a, b;
        cin >> a >> b;
        if (a > b) cout << ">" << endl;
        else if (a < b) cout << "<" << endl;
        else cout << "=" << endl;
    }
}