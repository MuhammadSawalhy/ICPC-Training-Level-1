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

const int N = 1e5 + 1;
int n, m, c, k;
string grid[N];
vector<int> ps[N];

int ps2d(int i, int j, int k, int l) {
    k = min(k, n - 1), l = min(l, m - 1);
    int ans = ps[k][l];
    if (j > 0)
        ans -= ps[k][j - 1];
    if (i > 0)
        ans -= ps[i - 1][l];
    if (i > 0 && j > 0)
        ans += ps[i - 1][j - 1];
    return ans;
}

// 0 or 1
bool check(int x) {
    int l = 2 * x - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // top left corner of the square
            int count = ps2d(i, j, i + l - 1, j + l - 1);
            if (count >= k)
                return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m >> c >> k;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        ps[i].assign(m, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ps[i][j] = grid[i][j] == '#';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ps[i][j] += ps[i][j - 1];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            ps[i][j] += ps[i - 1][j];
        }
    }

    // 00000001111111
    int s = 0, e = 1e9;

    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (check(mid)) {
            e = mid;
        } else {
            s = mid;
        }
    }

    // s -> 0
    // e -> 1

    debug(s, e);
    if (check(e))
        cout << e * c << endl;
    else
        cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
