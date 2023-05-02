// ﷽
// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

int32_t main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    const int N = 1e7;
    vector<int> mp(N), primes;
    for (int i = 2; i <= N; i++) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > N) break;
            mp[i * p] = p;
            if (i % p == 0) break;
        }
    }

    for (int i = 2; i <= 10; i++)
        cout << i << ' ' << mp[i] << endl;

    return 0;
}
