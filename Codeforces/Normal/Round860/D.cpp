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
    
    sort(ALL(a));

    ll X = a[n - 1] - a[0];

    if (X == 0) {
        cout << "No" << ENDL;
        return;
    }

    vi ans;
    ll act = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        int bg = a[l], en = a[r];
        bool positive = act > 0;
        if (abs(act + bg) < X) {
            act += bg;
            ans.pb(bg);
            l++;
        }
        else {
            act += en;
            ans.pb(en);
            r--;
        }
        if (positive) {
            if (act < 0)
                act = 0;
        }
        else {
            if (act > 0)
                act = 0;
        }
    }

    cout << "Yes" << ENDL;
    for (auto &x : ans)
        cout << x << ' ';
    cout << ENDL;
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}