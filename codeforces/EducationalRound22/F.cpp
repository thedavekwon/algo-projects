#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--) {

    }
}