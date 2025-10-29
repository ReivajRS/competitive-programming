#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    set<ll> a, b;
    vector<ll> c(n);

    FOR (i, 0, n) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    FOR (i, 0, n) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    FOR (i, 0, n)
        cin >> c[i];

    sort(ALL(c));

    multiset<ll> diffs;

    while (!a.empty()) {
        auto l = prev(a.end());
        auto r = b.lower_bound(*l);
        diffs.insert(*r - *l);
        a.erase(l), b.erase(r);
    }

    ll ans = 0;
    
    for (auto &x : diffs) {
        ans += x * c.back();
        c.pop_back();
    }

    cout << ans << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}