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
    ll n, k, x;
    cin >> n >> k >> x;

    vi a(n);
    FOR (i, 0, n)
        cin >> a[i];
    
    sort(a.rbegin(), a.rend());

    vi presum(n + 1);
    presum[0] = 0;
    FOR (i, 1, n + 1)
        presum[i] = presum[i - 1] + a[i - 1];

    ll ans = -2e18;
    FOR (i, 0, k + 1) {
        ll j = min(i + x, n);
        ll sum = presum.back() - presum[i];
        sum -= (presum[j] - presum[i]) * 2;
        ans = max(ans, sum);
    }

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