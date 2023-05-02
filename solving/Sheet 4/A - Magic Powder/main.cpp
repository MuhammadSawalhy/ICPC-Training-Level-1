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

    int n, k;
    cin >> n >> k;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    auto valid = [&](int cnt) -> bool {
        int extra = k;
        for (int i = 0; i < n; i++) {
            if (cnt * a[i] > b[i] + extra)
                return false;
            if (cnt * a[i] > b[i])
                extra -= cnt * a[i] - b[i];
        }
        return true;
    };

    // 111110000000
    // upper bound

    ll s = 0, e = 2e9 + 1;
    while (e - s > 1) {
        ll mid = (s + e) / 2;
        if (valid(mid)) {
            s = mid;
        } else {
            e = mid;
        }
    }

    cout << s;

    // for (int mx = 2000; mx > -1; mx--) {
    //     if (valid(mx))
    //         return cout << mx, 0;
    // }

    return 0;
}
