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

    string s;
    cin >> s;

    // divide into largest possible valid substring

    int ans = 0, l = 0, r = -1;
    int ps[(int)s.size() + 1];
    ps[0] = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        ps[i + 1] = ps[i] + (s[i] == '[');
    }

    stack<pair<char, int>> st;
    vector<int> valid_start(s.size(), 1e9);

    // [][]
    for (int i = 0; i < (int)s.size(); i++) {
        if (st.size() && (st.top().first == '(' && s[i] == ')' || st.top().first == '[' && s[i] == ']')) {
            int j = st.top().second;
            if (j > 0)
                j = min(j, valid_start[j - 1]);
            int x = ps[i  + 1] - ps[j];
            if (x >= ans) {
                ans = x;
                l = j;
                r = i;
            }
            valid_start[i] = j;
            st.pop();
        } else {
            st.push({ s[i], i });
        }
    }

    cout << ans << endl;
    cout << s.substr(l, r - l + 1) << endl;

    return 0;
}
