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

const int mod = 1e9 + 7;
vector<int> fact, inv_fact;

int fast_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void build_factorial(int n) {
    fact.push_back(1);
    for (int i = 1; i <= n; i++)
        fact.push_back(fact.back() * i % mod);
    inv_fact.resize(n + 1);
    inv_fact[n] = fast_power(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

int ncr(int n, int r) {
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

int32_t main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    build_factorial(1e6);

    cout << ncr(20, 15) << endl;

    return 0;
}

