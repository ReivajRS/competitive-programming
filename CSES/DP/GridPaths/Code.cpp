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
    int n;
    cin >> n;

    vector<vi> dp(n, vi(n, 0));
    dp[0][0] = 1;

    FOR (i, 0, n) {
        string s;
        cin >> s;
        if (i == 0 && s[0] == '*') {
            cout << 0 << ENDL;
            return 0;
        }
        FOR (j, 0, n) {
            if (s[j] == '*')
                continue;
            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][n - 1] << ENDL;

    return 0;
}