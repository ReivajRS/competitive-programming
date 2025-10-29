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
    string a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    FOR (i, 0, n) {
        if (a[i] != c[i] && b[i] != c[i]) {
            cout << "YES" << ENDL;
            return;
        }
    }
    cout << "NO" << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}