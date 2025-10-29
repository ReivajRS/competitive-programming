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
    vi a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int cnt = 0;
    FOR (i, 0, n - 1) {
        if ((a[i] <= a[n - 1] && b[i] <= b[n - 1]) || (a[i] <= b[n - 1] && b[i] <= a[n - 1]))
            continue;
        else {
            cout << "No" << ENDL;
            return;
        }
    }
    cout << "Yes" << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        // cout << "caso" << ENDL;
        solve();
    }
    return 0;
}