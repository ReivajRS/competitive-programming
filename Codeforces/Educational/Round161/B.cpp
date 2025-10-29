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

ll dp[300005][4];
ll comb(ll n, ll k) {
    if (k > n || k < 0)
        return 0;
    if (n == k || k == 0)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}

void solve() {
    ll n;
    cin >> n;
    
    vi a(n);
    unordered_map<ll, ll> c;
    FOR (i, 0, n) {
        cin >> a[i];
        c[a[i]]++;
    }
    
    sort(a.rbegin(), a.rend());

    unordered_map<ll, ll> r;
    FOR (i, 0, n) {
        r[a[i]] = i;
    }

    ll cnt = 0;
    FOR (i, 0, n) {
        ll k = c[a[i]];
        if (k >= 3) {
            cnt += comb(k, 3);
        }
        if (k >= 2 && n - r[a[i]] - 1 >= 1) {
            cnt += comb(k, 2) * (n - r[a[i]] - 1);
        }
        i = r[a[i]];
    }

    cout << cnt << ENDL;
}

signed main() { __
    memset(dp, -1, sizeof dp);
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}