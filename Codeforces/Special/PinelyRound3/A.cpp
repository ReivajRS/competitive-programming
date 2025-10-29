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
    int n;
    cin >> n;

    vector<bool> flag(4, false);

    FOR (i, 0, n) {
        ll x, y;
        cin >> x >> y;
        if (x < 0)
            flag[0] = true;
        if (y < 0)
            flag[1] = true;
        if (x > 0)
            flag[2] = true;
        if (y > 0)
            flag[3] = true;
    }

    int cnt = 0;
    FOR (i, 0, 4)
        if (flag[i])
            cnt++;
    
    cout << (cnt < 4 ? "YES" : "NO") << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}