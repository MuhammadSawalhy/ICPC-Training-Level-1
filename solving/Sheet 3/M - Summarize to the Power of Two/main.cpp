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
    ll a[n];
    map<int, int> fr;
    for (int i = 0; i < n; i++)
        cin >> a[i], fr[a[i]]++;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // deleting i, doesn't affect from [i + 1, n - 1]
        bool ok = false;
        for (int j = 0; j < 31; j++) {
            ok |= fr[(1 << j) - a[i]] > (a[i] == (1 << j) - a[i]);
        }
        ans += !ok;
    }

    cout << ans;

    return 0;
}
