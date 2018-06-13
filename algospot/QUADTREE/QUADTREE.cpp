#include <iostream>
#include <fstream>

using namespace std;

int ptr;
string input;

int solve_r();

int main() {
//    ifstream in("QUADTREE/input.txt");
//    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;
    getline(cin, input);

    while(tc--) {
        ptr = 0;
        getline(cin, input);
        //cout << input << endl;
        cout << solve_r() << endl;
        //cout << endl;
    }
}

int solve_r() {
    if (input[ptr] != 'x') return string(1, input[ptr++]);
    ptr++;
    string s1 = solve_r();
    string s2 = solve_r();
    string s3 = solve_r();
    string s4 = solve_r();
    return "x"+s3+s4+s1+s2;
}
