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
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vector<bool> pre(256, 0);
    pre[0] = 1;
    int XOR = 0, mx = 0;
    FOR (i, 0, n) {
        XOR ^= a[i];
        FOR (j, 0, 256) {
            if (pre[j])
                mx = max(mx, j ^ XOR);
        }
        pre[XOR] = 1;
    }
    cout << mx << ENDL;
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}