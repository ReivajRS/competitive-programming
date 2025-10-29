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
    vi a(n);
    for (auto &x : a)
        cin >> x;
    
    vi nxt(n);
    FOR (i, 0, n) {
        ll l = 2e9, r = 2e9;
        if (i > 0)
            l = a[i] - a[i - 1];
        if (i < n - 1)
            r = a[i + 1] - a[i];
        if (l < r)
            nxt[i] = i - 1;
        else
            nxt[i] = i + 1;
    }

    vi pref(n), rpref(n);
    pref[0] = 0;
    FOR (i, 1, n) {
        pref[i] = pref[i - 1] + (nxt[i - 1] == i ? 1 : a[i] - a[i - 1]);
    }
    rpref[n - 1] = 0;
    FOR (i, 1, n) {
        rpref[n - i - 1] = rpref[n - i] + (nxt[n - i] == (n - i - 1) ? 1 : a[n - i] - a[n - i - 1]);
    }

    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if(l <= r)
            cout << pref[r] - pref[l] << ENDL;
        else
            cout << rpref[r] - rpref[l] << ENDL;
    }
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}