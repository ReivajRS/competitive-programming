#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n), b(n);
    FOR (i, 0, n)
        cin >> a[i] >> b[i];

    ll cnt = 0, g = 0, l = 1;

    FOR (i, 0, n) {
        l = lcm(l, b[i]);
        g = gcd(g, a[i] * b[i]);
        if (g % l != 0)
            cnt++, l = b[i], g = a[i] * b[i];
    }

    cout << cnt + 1 << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}