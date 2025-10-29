#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ll a[3], d;

ll f(int i, int j, int k) {
    if (i + j + k == d) {
        ll ans = 0;
        a[0] += i;
        a[1] += j;
        a[2] += k;
        FOR (i, 0, 3) ans += a[i]  * a[i];
        ans += *min_element(a, a + 3) * 7LL;
        a[0] -= i;
        a[1] -= j;
        a[2] -= k;
        return ans;
    }
    return max({f(i + 1, j, k), f(i, j + 1, k), f(i, j, k + 1)});
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> d;
        sort(a, a + 3);
        ll ans = 0;
        if (d <= 13) ans = f(0, 0, 0);
        else {
            a[2] += d;
            FOR (i, 0, 3) ans += a[i] * a[i];
            ans += a[0] * 7LL;
        }
        
        cout << ans << ENDL;
    }
    return 0;
}