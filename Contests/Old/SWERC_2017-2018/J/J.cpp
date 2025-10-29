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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
    int n;
    cin >> n;
    ll a[n], b[n];
    FOR (i, 0, n)
        cin >> a[i];
    FOR (i, 0, n)
        cin >> b[i];

    vector<ll> s(3, 0);
    FOR (i, 0, n)
        s[i % 3] += b[i];

    vector<ll> ans(3, 0);
    FOR (c, 0, 3)
        FOR (i, 0, n)
            ans[c] += a[i] * s[(3 - (i % 3) + c) % 3];

    cout << ans[1] << " " << ans[2] << " " << ans[0] << ENDL;

    return 0;
}