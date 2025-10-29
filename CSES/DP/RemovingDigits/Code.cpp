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

    vi dp(1000001, INF);

    dp[n] = 0;

    ROF (i, n + 1, 0) {
        int num = i;
        while (num != 0) {
            int d = num % 10;
            num /= 10;
            if (i - d < 0)
                continue;
            dp[i - d] = min(dp[i - d], dp[i] + 1);
        }
    }

    cout << dp[0] << ENDL;
    
    return 0;
}