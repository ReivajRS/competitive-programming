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
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    
    sort(ALL(b));

    vi c;

    while (!b.empty() && b.back() >= a[0])
        c.pb(b.back()), b.pop_back();

    for (auto &x : a) {
        while (!b.empty() && b.back() >= x)
            c.pb(b.back()), b.pop_back();
        c.pb(x);
    }

    while (!b.empty())
        c.pb(b.back()), b.pop_back();

    for (auto &x : c)
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