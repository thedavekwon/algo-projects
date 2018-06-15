#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void pprint(const vector<int> &num) {
    for (const int n : num) {
        cout << n << " ";
    }
    cout << endl;
}

void normalize(vector<int> &num) {
    num.push_back(0);
    for (int i = 0; i < num.size()-1; i++) {
        if (num[i] < 0) {
            int burrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= burrow;
            num[i] += burrow * 10;
        } else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

void naive_normalize(vector<int> &num) {
    num.push_back(0);
    for (int i = 0; i < num.size()-1; i++) {
        if (num[i] < 0) {
            int burrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= burrow;
            num[i] += burrow * 10;
        } else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size()+b.size()+1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    //naive_normalize(c);
    return c;
}

void addTo(vector<int> &a, const vector<int> &b, int k) {
    if (a.size() < b.size() + k) a.resize(b.size()+k,0);
    for (int i = 0; i < b.size(); i++) {
        a[i+k] += b[i];
    }
}

void subFrom(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
}

vector<int> karatusba(const vector<int> &a, const vector<int> &b) {
    auto an = static_cast<int>(a.size());
    auto bn = static_cast<int>(b.size());

    if (an < bn) return karatusba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an == 1 || bn == 1) return multiply(a, b);
    if (an <= 50) return multiply(a, b);

    int half = an /2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+ min<int>(static_cast<int>(b.size()), half));
    vector<int> b1(b.begin()+min<int>(static_cast<int>(b.size()), half), b.end());

    vector<int> z2 = karatusba(a1, b1);
    vector<int> z0 = karatusba(a0, b0);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatusba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half+half);

//    normalize(ret);
    return ret;
}

int solve_r(const vector<int> &celebVector, const vector<int> &fanVector) {
    int cnt = 0;
    vector<int> result = karatusba(celebVector, fanVector);
    for (auto i = static_cast<int>(celebVector.size() - 1); i < fanVector.size(); ++i) {
        if (result[i] == 0) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    string celeb;
    string fan;

    vector<int> fanVector;
    vector<int> celebVector;

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> celeb;
        cin >> fan;
        fanVector.resize(fan.length(), 0);
        celebVector.resize(celeb.length(), 0);

        for (int i = 0; i < fan.length(); ++i) fanVector[i] = (fan[fan.length()-i-1] == 'M') ? 1 : 0;
        for (int i = 0; i < celeb.length(); ++i) celebVector[i] = (celeb[i] == 'M') ? 1 : 0;
        
        cout << solve_r(celebVector, fanVector) << endl;
    }
}