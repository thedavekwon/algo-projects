#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

int n;

bool splitArrayWithSameAverage(vector<int> &A) {
    int m = n/2, sum = accumulate(A.begin(), A.end(), 0);
    bool isPossible = false;
    for (int i = 1; i <= m; ++i) if (sum * i % n == 0) isPossible = true;
    if (!isPossible) return false;

    vector<unordered_set<int>> sums(m+1, unordered_set<int>());
    sums[0].insert(0);
    for (int num : A) {
        for (int i = m; i >= 1; --i) {
            for (const int t : sums[i-1]) {
                sums[i].insert(t+num);
            }
        }
    }

    for (int j = 1; j <= m; ++j) {
        if (sum*j%n == 0 && sums[j].find(sum*j/n) != sums[j].end()) return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << splitArrayWithSameAverage(A) << endl;
}