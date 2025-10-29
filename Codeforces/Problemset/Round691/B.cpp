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
    ll n;
    cin >> n;

    ll dp[1005];
    dp[0] = 1, dp[1] = 4, dp[2] = 4, dp[3] = 12, dp[4] = 9, dp[5] = 24;

    FOR (i, 6, n+1)
        dp[i] = (i & 1) ? dp[i-1]*2 + (i + 1) : ((i/2)+1) * ((i/2)+1);

    cout << dp[n] << ENDL;

    // cout << 1 + ( 3*n*(n + 4) + 2 - (n&1 ? -1 : 1)*(n*(n + 4) + 2) )/8 << ENDL;

    return 0;
}