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

    vi a(n), b(n);

    FOR (i, 0, n)
        cin >> a[i];
    FOR (i, 0, n)
        cin >> b[i];

    vector<pi> sorted(n);

    FOR (i, 0, n)
        sorted[i] = {a[i] + b[i], i};

    sort(RALL(sorted));

    ll ans = 0;

    FOR (i, 0, n)
        ans += (i%2 == 0 ? a[sorted[i].second]-1 : -b[sorted[i].second]+1);

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