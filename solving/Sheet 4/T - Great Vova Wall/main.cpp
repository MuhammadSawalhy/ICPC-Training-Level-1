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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int c[n], h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        c[i] = 1;
        h[i] = h[i] & 1;
    }

    int C[n], H[n];
    int sz = 0;

    auto canmerge = [&](int i, int j) {
        bool res = (C[i] + C[j] < 2 || H[i] == H[j]);
        return res;
    };

    auto merge = [&](int i, int j) -> pair<int, int> {
        if (C[i] == 1) return { (C[i] + C[j]) & 1, H[i] };
        return { (C[i] + C[j]) & 1, H[j] };
    };

    for (int i = 0; i < n; i++) {
        C[sz] = c[i], H[sz] = h[i];
        sz++;
        while (sz > 1 && canmerge(sz - 1, sz - 2)) {
            auto [newc, newh] = merge(sz - 1, sz - 2);
            sz--;
            C[sz - 1] = newc;
            H[sz - 1] = newh;
        }
    }

    cout << (sz == 1 ? "YES" : "NO");

    return 0;
}
