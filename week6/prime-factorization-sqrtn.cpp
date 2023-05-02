// ﷽
// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n = 12, N = n;

    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.push_back(i); // i is a prime
            n /= i;
        }
    }

    if (n != 1) {
        assert(n * n > N);
        primes.push_back(n);
    }

    for (auto fact : primes) 
        cout << fact << endl;

    return 0;
}
