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
    string s1, s2;
    cin >> s1 >> s2;

    int l = 0, r = 1;
    int n = SZ(s1) - 1;
    while (r <= n) {
        if (s1[0] == s1[l] && s2[0] == s2[l] && s1[r] == s1[n] && s2[r] == s2[n]) {
            cout << "YES" << ENDL;
            return;
        }
        l++, r++;
    }

    cout << "NO" << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}