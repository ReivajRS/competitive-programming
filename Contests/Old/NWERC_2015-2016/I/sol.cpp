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
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main () { __
    string s;
    cin >> s;

    ll x = 0, y = 0;

    FOR (i, 0, SZ(s)) {
        x *= 2, y *= 2;
        if (s[i] == '1')
            x++;
        if (s[i] == '2')
            y++;
        if (s[i] == '3')
            x++, y++;
    }

    cout << SZ(s) << ' ' << x << ' ' << y << ENDL;

    return 0;
}