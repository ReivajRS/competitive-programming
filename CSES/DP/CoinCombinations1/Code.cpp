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
    int n, x;
    cin >> n >> x;

    vi c(n), dp(1000001);
    for (auto &v : c) {
        cin >> v;
        dp[v] = 1;
    }

    FOR (i, 0, x + 1) {
        for (auto &v : c) {
            if (i >= v)
                dp[i] = (dp[i] + dp[i - v]) % MOD;
        }
    }

    cout << dp[x] << ENDL;

    return 0;
}