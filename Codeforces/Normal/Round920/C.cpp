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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    
    vi arr(n);
    for (auto &x : arr)
        cin >> x;
    
    sort(ALL(arr));

    ll now = 0;
    FOR (i, 0, n) {
        ll move = abs(arr[i] - now) * a;
        f -= min(move, b);
        now = arr[i];
        if (f <= 0) {
            cout << "NO" << ENDL;
            return;
        }
    }
    cout << "YES" << ENDL;
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}