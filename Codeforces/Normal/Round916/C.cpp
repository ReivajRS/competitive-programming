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
    int n, k;
    cin >> n >> k;

    vi a(n), b(n), maxi(n, 0), presum(n, 0);

    FOR (i, 0, n) {
        cin >> a[i];
        presum[i] = a[i];
        if (i > 0)
            presum[i] += presum[i-1];
    }

    FOR (i, 0, n) {
        cin >> b[i];
        maxi[i] = b[i];
        if (i > 0)
            maxi[i] = max(maxi[i-1], maxi[i]);
    }

    int mx = -1;

    FOR (i, 0, n) {
        if (i == k)
            break;
        int val = presum[i];
        val += (k-i-1) * maxi[i];

        mx = max(mx, val);
    }

    cout << mx << ENDL;
    
}

int main() {_
    int tc;
    cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;
}