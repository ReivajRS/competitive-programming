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

    vi cnt(101, 0);
    bool flag = false;
    FOR (i, 0, n) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1 || cnt[a[i]] >= 3)
            b[i] = 1;
        else if (cnt[a[i]] == 2)
            b[i] = flag ? 2 : 3, flag = true;
    }

    vector<bool> c(3, 0);

    for (auto &x : b)
        c[x - 1] = 1;
    
    if (c[0] && c[1] && c[2]) {
        for (auto &x : b)
            cout << x << ' ';
        cout << ENDL;
    }
    else
        cout << -1 << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}