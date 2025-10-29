#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vi diffs;
    FOR (i, 1, n) {
        diffs.pb(abs(a[i] - a[i - 1]));
    }
    sort(ALL(diffs));
    ll ans = 0;
    FOR (i, 0, n - k)
        ans += diffs[i];
    cout << ans << ENDL;
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}