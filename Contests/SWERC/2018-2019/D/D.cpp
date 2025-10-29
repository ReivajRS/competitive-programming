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
    int x, y, n;
    cin >> x >> y >> n;

    vector<pi> pts(100005, {1e9, -1e9});
    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b;
        pts[a] = {min(pts[a].first, b), max(pts[a].second, b)};
    }

    auto f = [&](int m) -> ll {
        ll sum = x - 1;
        
        FOR (i, 0, x) {
            if (pts[i].first == 1e9 || pts[i].second == -1e9)
                continue;
            if ((pts[i].second >= m && pts[i].first >= m) || (pts[i].second <= m && pts[i].first <= m))
                sum += max(abs(m - pts[i].first) * 2, abs(m - pts[i].second) * 2);
            else {
                sum += abs(m - pts[i].first) * 2;
                sum += abs(m - pts[i].second) * 2;
            }
        }

        return sum;
    };

    int l = 0, r = y - 1;
    while (r - l >= 3) {
        int diff = (r - l) / 3;
        int m1 = l + diff;
        int m2 = r - diff;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;   
    }

    cout << min({f(l), f(l + 1), f(r)}) << ENDL;

    return 0;
}