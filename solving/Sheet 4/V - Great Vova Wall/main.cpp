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
    }

    int C[n], H[n];
    int sz = 0;

    auto canmerge = [&](int i, int j) {
        if (C[i] + C[j] == 2)
            return H[i] == H[j];
        if (C[i] > C[j])
            return H[i] >= H[j];
        if (C[j] > C[i])
            return H[j] >= H[i];
        return true;
    };

    auto merge = [&](int i, int j) -> pair<int, int> {
        if (C[i] + C[j] == 2)
            return {0, H[i]};
        return {C[i] + C[j], max(H[i], H[j])};
    };

    for (int i = 0; i < n; i++) {
        C[sz] = c[i], H[sz] = h[i];
        sz++;
        while (sz > 1 && canmerge(sz - 1, sz - 2)) {
            auto [newc, newh] = merge(sz - 1, sz - 2);
            debug(C[sz-2], C[sz-1]);
            debug(H[sz-2], H[sz-1]);
            debug(newc, newh);
            sz--;
            C[sz - 1] = newc;
            H[sz - 1] = newh;
        }
    }

    cout << (sz == 1 ? "YES" : "NO");

    return 0;
}
