#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
long long solve(long long n, long long k);
long long recursive_solve(long long n, long long k, long long cnt);
 
int main() {
    ifstream in("./A.input");
    cin.rdbuf(in.rdbuf());
    int tc;
    long long n, k;
    cin >> tc;
        
    while(tc--) {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
 
long long solve(long long n, long long k) {
    return recursive_solve(n, k, 0);
}
 
long long recursive_solve(long long n, long long k, long long cnt) {
    if (n == 0) return cnt;
    if (n%k == 0) {
        return recursive_solve(n/k, k, cnt+1);
    }
    return recursive_solve(n-(n%k), k, cnt+(n%k));
}