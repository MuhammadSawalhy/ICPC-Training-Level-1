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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    bool people[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> people[i][j];

    int ans = 0;
    vector<int> teamans;

    for (int mask = 0; mask < 1 << n; mask++) {
        vector<int> team;
        for (int j = 0; j < n; j++) {
            if (mask >> j & 1) {
                team.push_back(j);
            }
        }

        bool ok = true;

        for (int j : team) {
            for (int i : team) {
                ok &= people[i][j];
            }
        }

        if (ok && team.size() > teamans.size())
            teamans = team;
    }
    cout << teamans.size() << endl;
    for (auto j : teamans)
        cout << j + 1 << " ";

    return 0;
}
