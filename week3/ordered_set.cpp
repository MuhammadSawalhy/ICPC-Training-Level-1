// ﷽
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

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
    // NOTE: we can't make ordered multiset
    // To do such a thing, use pair<int, int> (value, index)
    ordered_set<pair<int, int>> os;

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        cout << os.order_of_key({a, i}) + 1 << " ";
        os.insert({a, i});
    }

    return 0;
}
