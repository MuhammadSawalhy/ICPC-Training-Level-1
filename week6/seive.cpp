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

void is_prime() {
    const int n = 1e6;
    vector<bool> is_prime(n, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i < n; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j < n; j += i)
            is_prime[j] = 0;
    }

    int p;
    p = 2, cout << p << ' ' << is_prime[p] << '\n';
    p = 3, cout << p << ' ' << is_prime[p] << '\n';
    p = 4, cout << p << ' ' << is_prime[p] << '\n';
    p = 5, cout << p << ' ' << is_prime[p] << '\n';
    p = 6, cout << p << ' ' << is_prime[p] << '\n';
}

void fast_sieve() {
    // all these * 2 and / 2 are just to ignore all even numbers
    // don't represent them in memory or even loop over them
    const int NMAX = (int)1e9; // all prime up to billion
    bitset<NMAX / 2> bits;
    bits.set();
    vector<int> primes{2};
    for (int i = 3; i / 2 < bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
        for (auto j = (int64_t)i * i / 2; j < bits.size(); j += i)
            bits[j] = 0;
    }
}

void prime_factors() {
    const int n = 1e5;
    vector<vector<int>> prime_factors(n);

    for (int i = 2; i < n; i++) {
        if (prime_factors[i].size() > 0)
            continue;
        for (int j = i; j < n; j += i) {
            int n = j;
            while (n % i == 0)
                prime_factors[j].push_back(i), n /= i;
        }
    }

    for (auto fact : prime_factors[12])
        cout << fact << endl;
}

// space and time: O(log N)
void divs() {
    const int n = 1e6;
    vector<vector<int>> divs(n);

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            divs[j].push_back(i);
        }
    }

    for (auto fact : divs[12])
        cout << fact << endl;
}

// space and time: O(N)
void minimum_prime__fast_factorization() {
    const int N = 1e7;
    vector<int> mp(N), primes;
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > N) break;
            mp[i * p] = p;
            if (i % p == 0)
                break;
        }
    }

    int n = 20;

    // O(log n)
    while (mp[n] > 1) {
        cout << mp[n] << endl;
        n /= mp[n];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}
