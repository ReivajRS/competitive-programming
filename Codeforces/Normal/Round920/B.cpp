#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int cnt1 = 0;
    FOR (i, 0, n)
        cnt1 += (s1[i] == '1' && s2[i] == '0');
    int ans = 0;
    FOR (i, 0, n) {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] == '0' && s2[i] == '1') {
            if (cnt1 > 0)
                cnt1--;
            else
                ans++;
        }
        else
            ans++;
    }
    cout << ans << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}