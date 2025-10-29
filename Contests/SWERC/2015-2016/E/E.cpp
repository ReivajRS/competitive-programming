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

constexpr int MOD = INT_MAX;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int n;
vi a;
ll dp[2005][2005];

ll solve(int i, int ant) {
    if (i == n + 1) return 1;
    ll &ans = dp[i][ant];
    if (ans != -1)  return ans;

    ans = 0;

    if (a[i - 1] > ant) {
        if (a[i] < a[i - 1])
            ans = (ans + solve(i + 1, a[i - 1])) % MOD;
        if (a[i] > ant)
            ans = (ans + solve(i + 1, ant)) % MOD;
    }
    else {
        if (a[i] > a[i - 1])
            ans = (ans + solve(i + 1, a[i - 1])) % MOD;
        if (a[i] < ant)
            ans = (ans + solve(i + 1, ant)) % MOD;
    }

    return ans;
}

signed main() {_
    cin >> n;
    a.resize(n+1);

    FOR (i, 0, n+1) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << ENDL;
        return 0;
    }

    memset(dp, -1, sizeof dp);
    cout << solve(2, a[0]) << ENDL;
    
    return 0;
}