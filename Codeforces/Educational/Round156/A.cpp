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

    if (n < 6) {
        cout << "NO" << ENDL;
        return;
    }

    if ((n - 3) % 3 != 0 && (n - 3 != 2 && n - 3 != 1)) {
        cout << "YES" << ENDL;
        cout << n - 3 << " 2 1" << ENDL;
        return;
    }
    if ((n - 5) % 3 != 0 && (n - 5 != 4 && n - 5 != 1)) {
        cout << "YES" << ENDL;
        cout << n - 5 << " 4 1" << ENDL;
        return;
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