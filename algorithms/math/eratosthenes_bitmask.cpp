#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX_N = 50;
int n;
unsigned char sieve[(MAX_N+7)/8];

inline bool isPrime(int k) {
    return sieve[k>>3] & (1 << (k&7));
}

inline void setComposite(int k) {
    sieve[k>>3] = sieve[k>>3] & ~(1 << (k&7));
}

void eratosthenes() {
    memset(sieve,255,sizeof(sieve));
    setComposite(0);
    setComposite(1);
    n = 50;
    int sqrtn = int(sqrt(n));
    for (int i=2; i<=sqrtn; i++) {
        if(isPrime(i)) {
            for (int j=i*i; j<=n; j+=i) {
                setComposite(j);
            }
        }
    }
}

int main() {
    eratosthenes();
    int length = sizeof(sieve)/sizeof(sieve[0]);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 8; j++) {
            cout << ((sieve[i] & (1 << j)) != 0) << " ";
        }
        cout << endl;
    }
    cout << endl;
}