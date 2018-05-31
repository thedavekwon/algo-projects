//constants
#define    INF    987654321
#define    EPS    1e-9

#define    bitcount    __builtin_popcount
#define    gcd    __gcd

#define    forall(i, a, b)    for(int i = a; i < b; i++)
#define    foreach(v, c)      for(typeof((c).begin()) v = (c).begin(); v != (c).end(); v++)
#define    all(a)             a.begin(), a.end()
#define    in(a, b)           ((b).find(a) != (b).end())
#define    fill(a, v)         memset(a, v, sizeof(a))