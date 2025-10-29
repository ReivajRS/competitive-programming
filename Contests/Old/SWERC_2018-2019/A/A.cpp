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

signed main() { __
    int n, k;
    cin >> n >> k;

    bitset<1000005> bs;
    bs.set();

    ll mx = 0, off = 0;

    while (k--) {
        int x;
        cin >> x;
        for (int i = x; i <= n; i += x) {
            if (bs[i])
                off++;
            else
                off--;
            bs[i].flip();
        }
        mx = max(mx, off);
    }

    cout << mx << ENDL;

    return 0;
}