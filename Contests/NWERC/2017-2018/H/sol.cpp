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

inline ll f(ll a, ll b, ll c) {
    return a*a + b*b + c*c + 7 * min({a,b,c});
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> vals = {a, b, c};
    sort(vals.rbegin(), vals.rend());
    
    ll ans = 0;

    // Repartir a los 3 igual
    if (d % 3 == 0)
        ans = max(ans, f(vals[0] + d/3, vals[1] + d/3, vals[2] + d/3));

    // Darle todo al maximo
    ans = max(ans, f(vals[0] + d, vals[1], vals[2]));

    // Si los 2 menores son iguales, repartirles igual y darle lo restante al maximo
    if (vals[1] == vals[2]) {
        ll m = d/2;
        ans = max(ans, f(vals[0] + d - m*2, vals[1] + m, vals[2] + m));
    }

    // Tratar de igualar el menor al segundo menor y luego darle todo al maximo
    ll dif = vals[1] - vals[2];
    vals[2] += min(d, dif);
    d -= min(d, dif);
    ans = max(ans, f(vals[0] + d, vals[1], vals[2]));

    cout << ans << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}