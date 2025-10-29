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

int main() {_
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> cur(m + 1, 0), prev(m + 1, 0);

    if (a[0] != 0)
        prev[a[0]] = 1;
    else {
        FOR (i, 1, m + 1)
            prev[i] = 1;
    }

    FOR (i, 1, n) {
        if (a[i] != 0) {
            cur.assign(m + 1, 0);
            cur[a[i]] = prev[a[i] - 1] + prev[a[i]] + (a[i] < m ? prev[a[i] + 1] : 0);
            cur[a[i]] %= MOD;
        }
        else {
            FOR (j, 1, m + 1) {
                cur[j] = prev[j - 1] + prev[j] + (j < m ? prev[j + 1] : 0);
                cur[j] %= MOD;
            }
        }
        prev = cur;
    }

    ll ans = 0;

    if (a[n - 1] != 0)
        ans = prev[a[n - 1]];
    else {
        FOR (i, 1, m + 1)
            ans = (ans + prev[i]) % MOD;
    }

    cout << ans << ENDL;

    return 0;
}