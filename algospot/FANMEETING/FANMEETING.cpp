#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string celeb;
string fan;

vector<int> fanVector;
vector<int> celebVector;

bool check(int idx) {
    for (int i = 0; i < celeb.length(); ++i) {
        if(celeb[i] == 'M' && fan[idx+i] == 'M') {
            return false;
        }
    }
    return true;
}

int solve_r() {
    int cnt = 0;
    if (fan.length() < celeb.length()) return 0;
    for(int i = 0; i <= fan.length()-celeb.length(); i++) {
        if (check(i)) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> celeb;
        cin >> fan;
        /*fanVector.resize(fan.length());
        celebVector.resize(celeb.length());*/

        /*for (int i = 0; i < fan.length(); ++i) {
            if (fan[i] == 'F') fanVector[i] = 1;
            else fanVector[i] = 0;
        }
        for (int j = 0; j < celeb.length(); ++j) {
            if (celeb[j] == 'F') celebVector[j] = 1;
            else celebVector[j] = 0;
        }*/
        cout << solve_r() << endl;
    }
}