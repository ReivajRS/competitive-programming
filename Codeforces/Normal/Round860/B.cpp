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
    int m;
    cin >> m;
    unordered_map<int, int> last;
    FOR (i, 0, m) {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a) {
            cin >> x;
            last[x] = i;
        }
    }
    vi d(m, -1);
    for (auto &[k, v] : last)
        d[v] = k;
    vi ans;
    for (auto &x : d) {
        if (x == -1) {
            cout << -1 << ENDL;
            return;
        }
        ans.pb(x);
    }
    for (auto &x : ans)
        cout << x << ' ';
    cout << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}