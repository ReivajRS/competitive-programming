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
    ll n;
    cin >> n;

    vector<pi> c(n);
    FOR (i, 0, n) {
        ll a, x;
        cin >> a >> x;
        c[i] = {a, x};
    }

    ll l = -2e9, r = 2e9;
    FOR (i, 0, n) {
        if (c[i].first == 1)
            l = max(l, c[i].second);
        if (c[i].first == 2)
            r = min(r, c[i].second);
    }

    ll cnt = r - l + 1;

    FOR (i, 0, n) {
        if (c[i].first == 3 && c[i].second >= l && c[i].second <= r)
            cnt--;
    }
    
    cout << (cnt < 0 ? 0 : cnt) << ENDL;
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}