#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
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
    int n, k, d;
    cin >> n >> k >> d;

    vi a(n), v(k);

    FOR (i, 0, n)
        cin >> a[i];
    FOR (i, 0, k)
        cin >> v[i];

    auto incrementInterval = [&](int len) {
        FOR (i, 0, len)
            a[i]++;
    };

    auto getBenefit = [&]() {
        ll benefit = 0;
        FOR (i, 0, n)
            benefit += (a[i] == i+1);
        return benefit;
    };

    ll mx = -1;

    FOR (i, 0, min(2 * n, d)) {
        mx = max(mx, getBenefit() + (d - i - 1)/2);
        incrementInterval(v[i%k]);
    }

    cout << mx << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}